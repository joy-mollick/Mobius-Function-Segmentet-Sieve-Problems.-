
///  finding by prime factoring approach when number is so large 

ll getmobius(ll a)
{
    ll x=a,tmp=a;
    int cnt=0,now=0;
    for(ll j=2;j*j<=x;j++){
        now=0;
        if(x%j==0){
            while(x%j==0) now++,x/=j;
            if(now>1) return 0;
            cnt++;
        }
    }
    if(x!=1) cnt++;
    return (cnt&1)?-1:1;
}
