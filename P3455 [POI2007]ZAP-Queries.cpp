
/// Time-1.93 s
/// By Mobius Inversion ,we can get the formula for finding number of pairs(i,j) whose gcd is k ,where 1<=i<=n and 1<=j<=m .
/// problem link - https://www.luogu.com.cn/problem/P3455


#include<bits/stdc++.h>

using namespace std;

const int mx=60011;

typedef long long ll;

ll prime[mx];/// containing ith prime in it .
bool isprime[mx];
ll mobius[mx];/// containing mobius function of ith number
ll prefix_sum_mobius[mx];
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
	ll sum=0;
	for(int i=1;i<mx;i++)
    {
        sum+=mobius[i];
        prefix_sum_mobius[i]=sum;
    }
}

///it will return the number of pairs(i,j) where 1<=i<=n and 1<=j<=m whose gcd is equal to k.
ll calculation(ll n,ll m,ll k)
{
    n/=k;/// our ranges are  [ n/k ]
    m/=k;/// and  [ m/k ]
    if(n>m) swap(n,m);/// assuming n is minimum limit
    ll ans=0;
    ll next=0;
    for(ll d=1;d<=n;d=next+1ll)
    {
        next=min(n/(n/d),m/(m/d));/// d can run till up to min(n,m) ,so take minimum all time as gcd(n,m) may be maximum which will be equal to n .
        ans+=(prefix_sum_mobius[next]-prefix_sum_mobius[d-1])*(n/d)*(m/d);
    }
    return ans;
}

int main()
{
   genmobius();
   int tc;
   cin>>tc;
   while(tc--)
   {
   ll a,b,d;
   cin>>a>>b>>d;
   ll ans=calculation(a,b,d);
   cout<<ans<<endl;
   }
   return 0;
}
