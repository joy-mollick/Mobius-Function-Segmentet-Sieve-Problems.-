/*
Using mobius function ,we can prove that 
( n/gcd(k,n) ) for all k till n ,when k increases contiguously is 
equal to = summatory function phi(d)*d for all divisors d. 
*/



ll phi[mx];
ll gcd_sum[mx];

/// finding totient function of every number using sieve 
 void totient_sieve()
 {
     int i,p;
    for ( i=1;i<mx;++i)
        phi[i]=i;

    for( p=2;p<mx;++p)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for( i=2*p;i<mx;i+=p)
            {
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
 }

/// using formula phi(d)*d ,where d are all divisors of a number .
 void gcd_sum_sieve()

 {
     totient_sieve();
     ll i,j;
     for( i=1;i<mx;++i)
     {
         for( j=i;j<mx;j+=i)
         {
             gcd_sum[j]+=(i*phi[i]);/// d*phi(d) , where d is divisor of n
         }
     }
 }
