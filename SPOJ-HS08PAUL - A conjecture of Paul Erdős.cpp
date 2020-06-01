
/// Time-0.12s
/// Use Bitwise Sieve to make it fast and pre-calculate all values using dp array 

#include<bits/stdc++.h>

 using namespace std;

 const int mx=20000000+1;///10^7

 int status[mx>>5];
 bool is[mx];
 int dp[10000000];

 bool Check(int N,int pos){return (bool)(N & (1<<pos));}
 int Set(int N,int pos){	return N=N | (1<<pos);}

 void bitwise_sieve()
 {
     int i, j, sqrtN;
     sqrtN = int(sqrt(mx ));
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <mx; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j&31)   ;
	 		 }
		 }
	 }
 }

 bool is_prime(int n)
 {
     if(n==2) return true;
     else if(Check(status[n>>5],n&31)==0&&(n%2==1))
     {
         return true;
     }
     else return false;
 }

 void precal()
 {
     for(int i = 1;i * i < 10000000;++i)
     {
        for(int j = 1;j * j * j * j < 10000000;++j)

            {
            if(is_prime(i * i + j * j * j * j))
            {
                is[i * i + j * j * j * j]=1;
            }

            }
     }
     int cont=1;
     dp[2]=1;
     for(int i=3;i<10000000;i++)
     {
         if(is[i])
         {
             cont++;
         }
         dp[i]=cont;
     }

 }

 int main()
 {
     bitwise_sieve();
     precal();
     int tc;
     int n;
     scanf("%d",&tc);
     while(tc--)
     {
         scanf("%d",&n);
         printf("%d\n",dp[n]);
     }
     return 0;
 }
