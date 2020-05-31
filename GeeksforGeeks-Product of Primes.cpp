
/// It is formal implementation of printing primes in a range where l<=r<=10^12.
/// Using segmented-sieve algorithm

#include<bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 const ll mod=1e9+7;

 #define pb push_back

 vector<ll>primes;

 /// 1000000000000 it can be maximum R ,so take size of sqrt of this which is approximately 1000000
 const int mx=100000;

 bool prime[mx+1];/// for normal sieve

 ll L,R;

 void normal_sieve()
 {
      /// normal sieve O(nloglogn) complexity
     memset(prime,true,sizeof(prime));///mark them as true.
     for (ll i = 2; i <= mx; ++i) {
        if (prime[i]) {
            primes.pb(i);/// pushing all prime numbers
            for (ll j = i * i; j <= mx; j += i)
                prime[j] = false;
        }
    }
 }

 /// It is used for finding segmented sieve for different -different L and R
 void segmented_sieve()
 {

    if(L==1) L++;/// if starting is 1 increment it.
    int range=R-L+1;
    bool segprime[range];
    memset(segprime,true,sizeof(segprime));
    /// make all multiples of prime in range L to R mark
    for(int j=0;j<primes.size();j++)
    {
        ll p=primes[j];
        if(p*p<=R)/// if p is in the range
        {
            ll start=(L/p)*p;
            if(start<L) start+=p;
            /// above two lines for finding first multiple of p in the range L<=R
            for(start;start<=R;start+=p)/// traversing all multiple of prime p
            {
                if(start!=p) /// p is prime ,so p can't be composite ,if start=p ignore it
                    segprime[start-L]=false;/// make mark as composite
            }
        }
    }
    ll ans=1ll;
    for(int i=0;i<range;i++)
    {
        if(segprime[i])///if it is true
        {
            ans=(ans*(L+i))%mod;
        }
    }
    cout<<ans<<endl;
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     normal_sieve();
     int tc;
     cin>>tc;
     while(tc--)
     {
         cin>>L>>R;
         segmented_sieve();
     }
     return 0;
 }
