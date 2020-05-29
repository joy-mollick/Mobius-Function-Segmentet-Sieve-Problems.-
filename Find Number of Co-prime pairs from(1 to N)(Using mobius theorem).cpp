
/// Here precalculation takes O(N) time where ,N is maximum range 
/// And finding solution takes O(sqrt(n)) ,where n is taken as input 
/// Here solution is for number of testcases .

#include<stdio.h>
#include<ctype.h>
const int N=100000; long long ans;
int cnt,t,T,n,p[10000],v[N+10],mu[N+10],s[N+10];
void prework() {
    for (int i=2; i<=N; ++i) {
        v[i]||(p[++cnt]=i,mu[i]=-1);
        for (int j=1; j<=cnt&&1ll*p[j]*i<=N; ++j) {
            v[t=p[j]*i]=1;
            if (i%p[j]==0) break; mu[t]=-mu[i];
        }
        s[i]=s[i-1]+mu[i]; 
    }
}

 int read() { 
    int x=0; char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return x;
}
int main() {
    mu[1]=1,s[1]=1,prework(),T=read();
    for (int i=1; i<=T; ++i) {
        n=read(),ans=0;
        for (int l=1,r; l<=n; l=r+1) { 
            r=n/(t=n/l); 
            ans+=1ll*t*t*(s[r]-s[l-1]);
        }
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
