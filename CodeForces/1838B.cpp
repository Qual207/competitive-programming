/*
6/14/2023

Notes: I suck at constructive algorithms. I was unable to solve this problem as well. I made some decent observations, specifically noting that the permutations of size 1
and of size n will always be present in the array regardless of whichever two elements we swap. I also knew that each valid permutation would have "1" in it and I thought 
that by separating the "1" and "2" this would guarantee that no permutation could exist (outside of the 2 minimal ones). However, I abandoned this idea since I thought that
even if I separate "1" and "2", I could still have other permutations in between the 1 and 2. I then started trying to come up with a sol based on finding the max valid 
permutation in the array (outside of the whole array itself) and then swapping 1 with an element outside of this array. I thought this would work because every single perm 
in the array is found inside this maximum permutation so by "disrupting" this permutation I would also disrupt all of those other permutations. I actually think this might 
work but the implementation was too messy so I gave up.

If we have "6 7 1 3 2 4 5" I was trying to think of a way to remove "1" out of the block "1 3 2 4 5" so that none of the permutationis in "1 3 2 4 5" would exist. Instead of
thinking about moving 1 out, I should have thought about what to move IN. If I moved 7 IN to this permutation, where would I put it? I want to put in such a way that none
of the permutations in "1 3 2 4 5" can exist. The best way to do this is if I move 7 IN between the "1" and "2", because now the 1 and 2 are "cutoff" from any permutation 
of size less than "n". 
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		int n;
		cin >> n;
		vector<int> nums(n);

		int pos1;
		int pos2;
		int posn;
		for(int i=0; i<n; ++i)
		{
			cin >> nums[i];
			if(nums[i]==1) pos1 = i;
			else if(nums[i]==2) pos2 = i;
			else if(nums[i]==n) posn = i;
		} 

		pos2++, pos1++, posn++;

		if(pos2>pos1)
		{
			if(posn>pos2) cout << posn << " " << pos2 << "\n";
			else if(posn<pos1) cout << posn << " " << pos1 << "\n";
			else cout << "1 1\n";
		}
		else if(pos1>pos2)
		{
			if(posn>pos1) cout << posn << " " << pos1 << "\n";
			else if(posn<pos2) cout << posn << " " << pos2 << "\n";
			else cout << "1 1\n";
		}
		t--;
	}
}
