/// https://www.luogu.org/problemnew/show/P2257
/// Category : number theory + mobius  .(advanced) 

/// By mobius inverson , we can get the formula.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mx 100005

int prime[mx];
bool notprime[mx];
int mobius[mx];
int cnt;
int f[mx];

 void genmobius()
{
	mobius[1]=1;
    int i,j;
	for( i=2;i<mx;i++)
    {
		if(notprime[i]==false){prime[++cnt]=i; mobius[i] = - 1;}
		for( j=1;j<=cnt;j++)
            {
			if(prime[j]*i>=mx) break;
		    notprime[prime[j]*i]=true;
			if(i%prime[j]) mobius [i * prime [j]] = - mobius [i];
			else {mobius [i * prime [j]] = 0;break;}
		    }
	}

	for (int i = 1; i <= cnt; ++ i)
    {
        int p=prime[i];
        for ( j = p; j < mx; j+=p)
        {
            f[j] += mobius[j/p];
        }
    }

    for (int i = 1; i < mx; i++) f[i] += f[i - 1];

}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        genmobius();
        ll n,m;
        cin>>n>>m;
        if (n > m) swap(n, m);
        ll ans = 0;
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans += 1ll * (n / l)*(m / l)*(f[r] - f[l - 1]);
        }
       cout<<ans<<endl;

    return 0;
}
