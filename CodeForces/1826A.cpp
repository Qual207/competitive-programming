/*
6/3/2023

Notes: Not sure how this is a 1200 rated problem, even saying it's 1100 would be a bit of a overestimate. I was at first a bit confused by the wording of the problem and 
what it meant by people "contradicting" each other, but I quickly understood it just meant that everyone was lying. The idea of the problem was clear: Loop through, assume 
each person is the real truth teller and then check if they actually are telling the truth by seeing how many people would be "lying" (their number doesn't match the truth teller's).
However, this would answer the question of the i-th person says "There are l_i liars among us". The question actually reads that the i-th person says "There are AT LEAST l_i
liars among us". I missed this part, and so I had to look at the solution and realize that I misread the question. This was a easy fix luckily.
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

		int arr[n];
		for(int i=0; i<n; i++) cin >> arr[i];

		sort(arr, arr+n);
		int finalNum = -1;
		for(int i=0; i<n; i++)
		{
			int numLiars = i;
			int count = 0;
			for(int j=0; j<n; j++)
				{
					if(arr[j]>numLiars) count++;
				}
				if(count==numLiars)
				{
					finalNum = numLiars;
					break;
				}
		}

		cout << finalNum << "\n";
		t--;
	}
}
