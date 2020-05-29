
/// Time-1.18 s
/// By Mobius Inversion ,we can get the formula for finding sum of lcm(i,j) ,where 1<=i<=n and 1<=j<=m .
/// problem link - https://www.luogu.com.cn/problem/P1829
/// Here ,everything has been done using formula .


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mx=10000005;///till 10^7

const ll mod=20101009;

ll prime[mx];/// containing ith prime in it .
bool isprime[mx];
ll mobius[mx];/// containing mobius function of ith number
ll prefix_sum_mobius[mx];/// it holds value of prefix sum of mu(x)*x*x till i .   (mu(x)*x*x) formed from the formula. where x starts from1 to min(a,b) ,where a=n/d and b= m/d.
int cnt;
ll prefix_sum_of_numbers_till_i[mx];/// it holds  the summation of numbers from 1 to i .

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
        prefix_sum_mobius[i]=(prefix_sum_mobius[i-1] + (ll)i * (ll)i % mod * mobius[i]) % mod;
        prefix_sum_of_numbers_till_i[i]=(prefix_sum_of_numbers_till_i[i-1]+(ll)i)%mod;
    }
}

///it will return the number of pairs(i,j) where 1<=i<=n and 1<=j<=m whose gcd is equal to k.
ll calculation(int n,int m)
{
    int limit=min(n,m);
    ll ans=0;
    /// overall time-complexity of this two array is O( n* sqrt(n) ).
    for(int d=1;d<=limit;d++)///it is traversing for finding d till min(n,m) ,Time-Complexity O(n),assuming n is minimum
    {
        int a=(n/d);
        int b=(m/d);
        int limit1=min(a,b);
        ll res_per_d=0ll;
        for(int x=1,next;x<=limit1;x=next+1)///it will compute the second part of the summation equation ,using dividing into blocks technique,Complexity O(sqrt(n)),assuming limit1 is n
        {
            next= min(a / (a / x),b / (b / x));/// it will hold the last point of interval
            res_per_d += ((prefix_sum_mobius[next] - prefix_sum_mobius[x-1] + mod) % mod * prefix_sum_of_numbers_till_i[a / x] % mod * prefix_sum_of_numbers_till_i[b / x] % mod),res_per_d %= mod;
        }
        ans+=(res_per_d * (ll)(d)%mod);
        ans%=mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   genmobius();
   int n,m;
   cin>>n>>m;
   ll ans=calculation(n,m);
   cout<<ans<<endl;
   return 0;
}
