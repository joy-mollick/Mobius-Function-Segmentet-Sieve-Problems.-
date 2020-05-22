/// Source Limit is so strict !!! so I removed all my important comments line per every important operation lost flexibility of my code
/// Time-0.450s 
#include<iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define il inline
#define ri register
#define mx 10000001
template<class free>
il void read(free&);
inline void genmobius();
int prime[mx];
bool notprime[mx];
int mobius[mx];
int cnt;
inline void genmobius()
{
	mobius[1]=1;
	ri int i,j;
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
	ri int sz;
    sz=0;
    for( i=2;i<mx;i++)
    {
        if(mobius[i]==0) continue;
        prime[sz]=i;
        sz++;
    }
}
int main()
{
   genmobius();
   int tc;
   ll n;
   read(tc);
   ll number_containing_squred_numbers=0ll,ans;
   while(tc--)
   {
        number_containing_squred_numbers&=0;
        read(n);
        for(int i=0;i<6079290;i++)
        {
            ll num=(ll)prime[i];
            ll sqr=(ll)num*(ll)num;
            if(sqr>n) break;
            ll multiple=n/sqr;
            if(mobius[num]==-1) number_containing_squred_numbers+=multiple;
            else  number_containing_squred_numbers-=multiple;
        }
        ans=(n-number_containing_squred_numbers);
        printf("%lld\n",ans);
   }
   return 0;
}
 
template<class free>
il void read(free &x){
    x&=0;ri char c;while(c=getchar(),c<'0'||c>'9');
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
 
