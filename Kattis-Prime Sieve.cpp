
/// You can't do it with normal sieve 
/// You have to use bitwise sieve
/// Bitwise Sieve 
/// Time-0.33s

#include<bits/stdc++.h>

 using namespace std;
 
 const int mx=1e8+1;

 int status[mx>>5];/// mx/32

 bool Check(int N,int pos){return (bool)(N & (1<<pos));}
 int Set(int N,int pos){	return N=N | (1<<pos);}

 void bitwise_sieve()
 {
     int i, j, sqrtN;
     sqrtN = int(sqrt(mx ));
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)/// i>>5 means i/32.i&31 means for i%32
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
     int n,v;
    cin >>v>> n;
       unsigned cont=1;
      for(int i=3;i<=v;i+=2)
     {
         if(Check(status[i>>5],i&31)==0 )
         {
             cont++;
         }
     }
     cout<<cont<<endl;
    while(n--)
    {
        int x;
        cin >>x;
        if((Check(status[x>>5],x&31)==0 && (x%2==1) && (x!=1))||(x==2))/// i>>5 means i/32. i&31 means for i%32
         {
           cout<<"1"<<'\n';
         }
         else
         {
            cout<<"0"<<'\n';
         }
    }
     return 0;
 }
