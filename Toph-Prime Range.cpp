
/// Bitwise Sieve implementation
/// Time-0.6s 

#include<bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 vector<ll>primes;

 #define pb push_back

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
     int cont=1;
     primes.pb(0ll);
     primes.pb(2ll);
     for(int i=3;i<mx;i+=2)
     {
         if(Check(status[i>>5],i&31)==0)/// i>>5 means i/32. i&31 means for i%32
         {
             cont++;
             primes.pb(i);
             primes[cont]=primes[cont]+primes[cont-1];///prefix sum of primes
         }
     }
     int n;
    cin >> n;
    while(n--)
    {
        int x,y;
        cin >> x >> y;
        ///x--;y--;
        cout << (primes[y]-primes[x-1])<< endl;
    }
     return 0;
 }
