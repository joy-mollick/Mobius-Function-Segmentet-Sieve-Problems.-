
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mx 100005

int prime[mx];
bool notprime[mx];
int mobius[mx];
int cnt;
 void genmobius()
{
	mobius[1]=1;
	 int i,j;
	for( i=2;i<mx;i++){
		if(notprime[i]==false){prime[++cnt]=i; mobius[i] = - 1;}
		for( j=1;j<=cnt;j++)
            {
			if(prime[j]*i>=mx) break;
		    notprime[prime[j]*i]=true;
			if(i%prime[j]) mobius [i * prime [j]] = - mobius [i];
			else {mobius [i * prime [j]] = 0;break;}
		}
	}
}

/// how many numbers till x are not composed with square form .
ll counts(ll x)
{
    ll ans=x;
    ll t=sqrt(x);
    ll numbers_containing_squared=0ll;
    for(ll i=2;i<=t;i++)
    {
        if(mobius[i]==0) continue;
        ll multiples=x/(i*i);
        /// using inclusion-exclusion principle 
        if(mobius[i]==-1)
            numbers_containing_squared+=multiples;
        else
            numbers_containing_squared-=multiples;
    }
    ans=ans-numbers_containing_squared;
    return ans;/// containing no number composed with square form
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
       genmobius();
       ll n;
       cin>>n;
       ll l=1ll;
       ll r=10000000000;
       ll mid,res;
       /// binary_search to find nth square-free number 
       while(l<=r)
       {
           mid=(l+r)>>1ll;
           if(counts(mid)<n)
           {
               l=mid+1ll;
           }
           else
           {
               r=mid-1;
               res=mid;
           }
       }
       cout<<res<<endl;
}
