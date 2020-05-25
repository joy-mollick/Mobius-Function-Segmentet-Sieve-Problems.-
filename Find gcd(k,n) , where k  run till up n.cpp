/*
BY using mobius inversion theorem , we can prove that
gcd(k,n) , where k starts with 1 and run till up n is equal to = phi(n/d)*d ,where d are all divisors of n .

Here is sieve implementation of that formula.
*/

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

 void gcd_sum_sieve()

 {
     totient_sieve();
     for(ll i=1;i<mx;i++)
     {
         for(ll j=i;j<mx;j=j+i)
         {
             gcd_sum[j]+=1ll*i*phi[j/i];
         }
     }
 }
 
 ///here by using,gcd_sum[i] is our answer .for all summatory function gcd(k,n) , where k starts with 1 and run till up n .
