
/// Time-0.18s
/// It should be solved with mobius function but for many queries it is better to use totient sieve 

#include<bits/stdc++.h>

using namespace std;
const int mx=1e5+1;
typedef  long long ll;

ll phi[mx];
ll ans[mx];

void totient_sieve()
 {
    for (int i=1;i<mx;i++)
        phi[i]=i;

    for(int p=2;p<mx;p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(int i=2*p;i<mx;i=i+p)
            {
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
 }

void pre_cal()
{
    ans[1]=phi[1];
    for(int i=2;i<mx;i++)
    {
        ans[i]=ans[i-1]+phi[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   totient_sieve();
   /// totient_sieve calculation ended.
   pre_cal();
   /// answer calculated
   ll tc,n;
   cin>>tc;
   int cas=0;
   while(tc--)
   {
       cas++;
       cin>>n;
       ll total_pairs=(n*(n+1))/2;
       ll res=total_pairs-ans[n];
       cout<<"Case "<<cas<<": "<<res<<endl;
   }
   return 0;
}
