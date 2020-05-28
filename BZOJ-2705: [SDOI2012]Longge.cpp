
/// Problem link - http://www.lydsy.com/JudgeOnline/problem.php?id=2705
/// Use google translator to translate question into English.
/// Time-2076 ms
/// Here formula has been found by using mobius inversion theorem.
/// summatory function phi(n/d)*d for all d (divisors of n) .

#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int mx=1e6+1;

ll phi[mx];

/// it will store phi function for value less or equal than 10^6.
void totient_sieve()
 {
    for (ll i=1;i<mx;i++)
        phi[i]=i;

    for(ll p=2;p<mx;p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(ll i=2*p;i<mx;i=i+p)
            {
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
 }

 /// it will find phi function for big number
 ll totient(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   totient_sieve();
   ll n;
   cin>>n;
   ll ans=0ll;
   for(ll d=1;d*d<=(n);d++)
   {
       if(n%d==0)/// i and (n/i) are divisors
       {
           if(d*d!=n)
            ans+=1ll*(n/d)*phi[d];
            if((n/d)>1000000)/// out of our calculated range
            ans+=1ll*(d)*(totient((n/d)));
            else
            ans+=1ll*(d)*(phi[(n/d)]);
       }
   }
   cout<<ans<<endl;
   return 0;
}
