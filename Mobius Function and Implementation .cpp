/*
The Möbius function is an arithmetic function of a natural number argument n with μ(1)=1, 
μ(n)=0 if n is divisible by the square of a prime number, 
otherwise μ(n)=(−1)k, where k is the number of prime factors of n.

The Möbius function is a multiplicative arithmetic function.
This function was introduced by A. Möbius in 1832.
*/

/// Here I implemented a much faster linear sieve by calculating mobius function of every number till 1000000. 
/// Its time complexity is O(2*1000000) .


#include<bits/stdc++.h>

using namespace std;
int prime[1000060];/// containing ith prime in it .
bool isprime[1000060];
int mobius[1000060];/// containing mobius function of ith number
int cnt;

void genmobius()

{
	memset(isprime,true,sizeof(isprime));/// initialize all with true.
	
	mobius[1]=1;/// mobius function of one is 1 .
	
	for(int i=2;i<=1000000;i++){
            
		if(isprime[i]==true){/// means i is prime
			prime[++cnt]=i;
			 mobius[i] = - 1; /// if it is prime, a prime factor only, so mobius = - 1.
		}
    
		for(int j=1;j<=cnt;j++)
            
            {
                
			if(prime[j]*i>1000000) break;/// greater than our range.
			 
		    isprime[prime[j]*i]=false;/// this number is not prime .
        
			if(i%prime[j]){
				 mobius [i * prime [j]] = - mobius [i];/// (- 1) ^ k, k is the number of prime factors , so here prime[j] is added in new number .
             /// so the mobius function will be reversed if -1 then it will be -(-1) = 1 ,if 0 ,then -(0)=0 i.e. square of a prime factor is inside new number (i*prime[j]), so no change .
			}
			
			else {
				 mobius [i * prime [j]] = 0; /// number (i*prime[j]) contains square of a prime factor
				break;
			}
			
		}
	}
}
int main(){
   genmobius();

   ///printing  mobius function of every number till 1000000
   for(int i=1;i<=1000000;i++)
   cout<<mobius[i]<<" ";

   return 0;
}
