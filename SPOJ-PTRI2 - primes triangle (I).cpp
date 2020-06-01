
/// Time-2.25s
/// Use Bitwise Sieve to make it fast and pre-calculate all rows-columns 

#include<bits/stdc++.h>

 using namespace std;

 const int mx=1e8+1;

 int status[mx>>5];
 pair<int,int> dp[mx];

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

 void precal()
 {
     dp[2]=make_pair(1,1);///first one
     int row=1;
     int column=1;
     for(int i=3;i<mx;i+=2)
     {
         if(Check(status[i>>5],i&31)==0)/// prime
         {
                column++;
                if(column>row)///every ith row can have maximum i columns
                {
                    column=1;
                    row++;
                }
                dp[i]=make_pair(row,column);
         }
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
         if(Check(status[n>>5],n&31)==0&&(n%2==1)||(n==2))
         printf("%d %d\n",dp[n].first,dp[n].second);
         else
         printf("-1\n");
     }
     return 0;
 }
