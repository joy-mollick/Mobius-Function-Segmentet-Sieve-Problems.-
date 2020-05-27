
/// solve with inclusion-exclusion and mobius function 
/// Time - 0.06s


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int prime[1000001];/// containing ith prime in it .
bool isprime[1000001];
int mobius[1000001];/// containing mobius function of ith number
ll freq[1000001];
int cnt;

void genmobius()

{
	memset(isprime,true,sizeof(isprime));/// initialize all with true.

	mobius[1]=1;/// mobius function of one is 1 .

	for(int i=2;i<=1000000;i++){

		if(isprime[i]==true){/// means i is prime
			prime[++cnt]=i;
			 mobius[i] = - 1; /// if it is prime, a prime factor only, so mobius = - 1.
		}

		for(int j=1;j<=cnt;j++)

            {

			if(prime[j]*i>1000000) break;/// greater than our range.

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
}
int main(){
   genmobius();
   /// mobius calculation ended.
    int tc,v,n;
    cin>>tc;
    n=tc;
    int maxi=0ll;
    while(tc--)

    {
        cin>>v;
        freq[v]++;
        maxi=max(maxi,v);
    }
    ll gcd_greater_than_one=0ll;
    ll triplets=0ll;
    for(int i=2;i<=maxi;i++)
    {
        int j=i;
        int counts_of_multiple_i=0;
        while(j<=maxi)
        {
            counts_of_multiple_i+=freq[j];
            j=j+i;/// increasing by value i ,all multiples of i .
        }
        if(mobius[i]==0) continue; /// it is not square-free,ignore it
        triplets=1ll * counts_of_multiple_i * (counts_of_multiple_i - 1) * (counts_of_multiple_i - 2) / 6ll;
        if(mobius[i]==-1)///i has odd prime factors
            gcd_greater_than_one+=(triplets);
        else /// i has even prime factors
            gcd_greater_than_one-=triplets;
    }
    /// subtract our got triplets from total triplets ,it is answer
    ll ans=1ll * n * (n - 1) * (n - 2) / 6 - gcd_greater_than_one;
    cout<<ans<<endl;
   return 0;
}
