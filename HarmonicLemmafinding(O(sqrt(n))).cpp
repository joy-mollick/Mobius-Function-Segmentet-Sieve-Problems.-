
/*

Finding (n/i) for all i from 1 to n.
like -> (n/1)+(n/2)+(n/3)+(n/4)+......(n/n).
This formula, O (n) calculation is very obvious. However, sometimes due to the requirements of multiple sets of data, 
O( n ) not be the correct time complexity. Then this time, we have an O (sqrt(n)) approach. 

For each ⌊n/i⌋ we can find through the table (or rational proof) that there are many ⌊n/i⌋ values are the same, 
and They are distributed in a block shape; then through various methods such as playing tables, 
we were pleasantly surprised to find that for each block with the same value, its last number is n / ( n / i ) . 
After drawing this conclusion, we can do O (sqrt(n)) processing.

And this calculation is very necessary for further any calculation regarding Mobius Inversion problem.

*/


/// this give the summation of any (n/1)+(n/2)+(n/3)+(n/4)+......(n/n). series.
for(int l=1,r;l<=n;l=r+1)
{
	r=n/(n/l);
	ans+=(r-l+1)*(n/l);
}
