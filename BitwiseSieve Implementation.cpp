
/// Bitwise Sieve implementation,less time-memory consuming algorithm
/// Formal Implementation upto 10^8

#include<bits/stdc++.h>

 using namespace std;

 const int mx=1e8+1;

 int status[mx/32];

 bool Check(int N,int pos){return (bool)(N & (1<<pos));}
 int Set(int N,int pos){	return N=N | (1<<pos);}

 void bitwise_sieve()
 {
     int i, j, sqrtN;
     sqrtN = int(sqrt(mx ));
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <mx; j += (i<<1) )
			 {
				 status[j/32]=Set(status[j/32],j % 32)   ;
	 		 }
		 }
	 }
 }

 int main()
 {
     bitwise_sieve();
     int cont=1;
     printf("2\n");
     for(int i=3;i<mx;i+=2)
     {
         if(Check(status[i/32],i%32)==0)
         {
             cont++;
             if(cont%100==1)
                printf("%d\n",i);
         }
     }
     return 0;
 }
