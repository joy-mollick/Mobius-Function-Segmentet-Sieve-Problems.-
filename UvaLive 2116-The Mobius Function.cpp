
/// Time- 0.003s

#include<bits/stdc++.h>

using namespace std;
const int mx=10001;
int prime[mx];/// containing ith prime in it .
bool isprime[mx];
int mobius[mx];/// containing mobius function of ith number
int cnt;

void genmobius()

{
	memset(isprime,true,sizeof(isprime));/// initialize all with true.

	mobius[1]=1;/// mobius function of one is 1 .

	for(int i=2;i<mx;i++){

		if(isprime[i]==true){/// means i is prime
			prime[++cnt]=i;
			 mobius[i] = - 1; /// if it is prime, a prime factor only, so mobius = - 1.
		}

		for(int j=1;j<=cnt;j++)

            {

			if(prime[j]*i>=mx) break;/// greater than our range.

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
   int n, flag = 0;
    while(~scanf("%d",&n) && n != -1) {
        if(flag)
            printf("\n");
        flag = 1;
        printf("M(%d) = %d\n", n, mobius[n]);
    }
    return 0;
}
