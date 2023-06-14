/*
6/13/2023

Notes: I failed this problem sort of. I made enough progress to realize that I had to look at subsequences of "10" since those instantly require a flip. I was thinking that 
I need 2 pointers to keep searching to the left of the 1 and the right of the 0 in "10" so that I can optimize the idea of getting a block of 1's adjacent to a block of 0's.
I completely ignored / forgot about how this problem is really just asking us to fill in the "?" places. 

I would approach this problem by first using the observation I made about how everytime you see the block "10" then we're required to flip that block eventually. Then if we
have multiple blocks of "10" then each of these blocks will require their own individual flip (which would add to the total cost). To prove this, you can realize that if we
tried to combine the blocks of "10", we would have a block of "01" somewhere in the middle which would become "10" once flipped and thus you would still require another flip 
for this new block. Now, since each block of "10" requires its own individual flip then the best we can do with the "?" characters is to reduce the number of "10" blocks. For
example, if we have the sequence "??10??" we want to make this "111000" that way we still technically just have a "10" block. This is a second good observation to make: we can
take any number of consecutive "0's" or "1's" and just treat them as a single "0" or "1". Thus, logically we realize that we can just make each question mark the same value 
as the previous value since this will only add to the giant "11...1100...00" block or just not do anything. 

Also this solution works if you set each "?" to be equal to the value right after it (following the same logic as before). I implemented it this way and also got AC. 

Actually, here's a better way to summarize the approach (maybe a new solution). If we look at the sample case: "0?1?10?10" we can think of the "barebone" or "skeletal" form 
of this sequence to be the sequence without any "?" meaning it would become "0 1 10 10". Also, any consecutive numbers can be grouped as one since whenever we reverse the numbers
we're automatically gonna group them together. So the sequence becomes "0 1 0 1 0" and this is the optimal sequence and tells us the minimum cost. This also leads us to realize
that with whatever value we substitute for "?", it can only require us to add another operation or not do anything (it will never reduce the number of operations required 
since the minimum number of operations is already set from all the numbers outside of the question marks). So we just want the "?" to not do anything and thus we make them 
equal to either the number before or after it that way it can just be grouped with that number and have no affect on the total number of operations.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		string s;
		cin >> s;

		if(s[0]=='?')  s[0] = '0';

		for(int i=1; i<s.length(); i++)
		{
			if(s[i]=='?')
			{
				s[i] = s[i-1];
			}
		}

		cout << s << "\n";
		t--;
	}
}
