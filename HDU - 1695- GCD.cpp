
/// Time-62ms
/// By Mobius Inversion ,we can get the formula for finding sum of gcd(i,j)=k ,where 1<=i<=n and 1<=j<=m .
/// Here one especial think is ,(2,3) and (3,2) pairs are treated as one ,so be careful about this .


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mx=1000005;///till 10^6

ll prime[mx];/// containing ith prime in it .
bool isprime[mx];
ll mobius[mx];/// containing mobius function of ith number
ll prefix_sum_mobius[mx];/// it holds value of prefix sum of mu(x)*x*x till i .   (mu(x)*x*x) formed from the formula. where x starts from1 to min(a,b) ,where a=n/d and b= m/d.
int cnt;

void genmobius()

{
	memset(isprime,true,sizeof(isprime));/// initialize all with true.

	mobius[1]=1;/// mobius function of one is 1 .

	for(ll i=2;i<mx;i++){

		if(isprime[i]==true){/// means i is prime
			prime[++cnt]=i;
			 mobius[i] = - 1; /// if it is prime, a prime factor only, so mobius = - 1.
		}

		for(ll j=1;j<=cnt;j++)

            {

			if(prime[j]*i>=mx) break;/// greater than our range.

		    isprime[prime[j]*i]=false;/// this number is not prime .

			if(i%prime[j]){
				 mobius [i * prime [j]] = - mobius [i];/// (- 1) ^ k, k is the number of prime factors , so here prime[j] is added in new number .
             /// so the mobius function will be reversed if -1 then it will be -(-1) = 1 ,if 0 ,then -(0)=0 i.e. square of a prime factor is inside new number (i*prime[j]), so no change .
			}

			else {
				 mobius [i * prime [j]] = 0; /// number (i*prime[j]) contains square of a prime factor
				break;
			}

		}
	}
	for(int i=1;i<mx;i++)
    {
        prefix_sum_mobius[i]=(prefix_sum_mobius[i-1] + mobius[i]);
    }
}

///it will return the number of pairs(i,j) where 1<=i<=n and 1<=j<=m whose gcd is equal to k.
ll calculation(int n,int m,int k)
{
        ll ans=0;
        ll N=(n/k);
        ll M=(m/k);
        ll limit=min(N,M);
        ll next=0;
        for(ll d=1;d<=limit;d=next+1)///it will compute the second part of the summation equation ,using dividing into blocks technique,Complexity O(sqrt(n)),assuming limit1 is n
        {
            next= min(N / (N / d),M / (M / d));/// it will hold the last point of interval
            ans += (prefix_sum_mobius[next] - prefix_sum_mobius[d-1] )*(N/d)*(M/d);
        }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  ///  cout.tie(NULL);
   genmobius();
   int tc;
   cin>>tc;
   int cas=0;
   while(tc--)
   {
   cas++;
   int a,b,c,d,k;
   cin>>a>>b>>c>>d>>k;
   if(k==0)
   {
       printf("Case %d: 0\n",cas);
       continue;
   }
   if(b>d)swap(b,d);/// assuming b is always small.
   ll ans_with_duplicates=calculation(b,d,k);/// this answer count the pairs (i,j) and (j,i) as different .
   ll res=calculation(b,b,k)/2;/// this answer count all duplicate pairs like (i,j) ans (j,i)
   ll final_answer=ans_with_duplicates-res;/// answer which count pairs (i,j) and (j,i) as same
   printf("Case %d: %lld\n",cas,final_answer);
   }
   return 0;
}
