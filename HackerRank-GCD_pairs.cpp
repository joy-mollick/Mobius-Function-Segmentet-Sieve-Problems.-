
/// You have to answer the queries ,how many pairs of elements of the array holds the gcd equal to given k .
/// Problem Link- https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao-returns/challenges/gcd-pairs/problem

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int prime[100001];/// containing ith prime in it .
bool isprime[100001];
int mobius[100001];/// containing mobius function of ith number
ll freq[100001];/// it holds frequency of ith number in array
ll ans[100001]; /// It holds the the number of pairs whose gcd is equal to k .
ll freq_sum[100001];/// it holds all frequency of multiples of i .

int cnt;

void genmobius()

{
	memset(isprime,true,sizeof(isprime));/// initialize all with true.

	mobius[1]=1;/// mobius function of one is 1 .

	for(int i=2;i<=100000;i++){

		if(isprime[i]==true){/// means i is prime
			prime[++cnt]=i;
			 mobius[i] = - 1; /// if it is prime, a prime factor only, so mobius = - 1.
		}

		for(int j=1;j<=cnt;j++)

            {

			if(prime[j]*i>100000) break;/// greater than our range.

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

int main()
{
    genmobius();
   /// mobius calculation ended.
    int tc,v,n,q,k;
    cin>>tc>>q;
    n=tc;
    int mx=0;
    while(tc--)

    {
        cin>>v;
        freq[v]++;
        mx=max(mx,v);
    }

    for(int i=1;i<100001;i++)
    {
        for(int j=i;j<100001;j=j+i)
        {
            freq_sum[i]+=freq[j];/// keep number of frequency of multiples of ith number
        }
    }

    for(int gcd=1;gcd<=mx;gcd++)
    {
        /// here we have to be carefull ,we have to count the pair of multiples of only gcd ,but it counts some numbers of pairs which are also multiples of gcd's multiple
        /// So we have to exclude those pairs of multiples of gcd which are also multiples of gcd's multiple.
        /// we have to count those pairs of multiples which are only and only multiples of gcd not multiples of other gcd's multiples
        /// And the pairs of these numbers will give you only gcd equal to gcd.
        ll multiples_of_gcd_pairs=freq_sum[gcd]*freq_sum[gcd];
        ll exclusion_numbers_pairs =0ll;
        for(int j=2*gcd;j<=mx;j=j+gcd)/// start from very fast multiple of gcd .
        {
           if(mobius[j/gcd]==0) continue;/// (j/gcd) is not square free,ignore it.
           else if(mobius[j/gcd]==-1) /// we have to include it
           {
               exclusion_numbers_pairs+=freq_sum[j]*freq_sum[j];
           }
           else
           {
               exclusion_numbers_pairs-=freq_sum[j]*freq_sum[j];
           }
        }
        ll pairs_multiples_of_only_gcd=multiples_of_gcd_pairs-exclusion_numbers_pairs;
        pairs_multiples_of_only_gcd+=freq[gcd];
        ll number_of_pairs=(pairs_multiples_of_only_gcd)/2ll;/// it has counted every pair (i,j) two times ,so divide it by two
        ans[gcd]=number_of_pairs;
    }
    while(q--)
    {
        cin>>k;
        cout<<ans[k]<<endl;/// number of pairs (i,j) where i<=j of given array whose gcd is equal to k
    }

   return 0;
}
