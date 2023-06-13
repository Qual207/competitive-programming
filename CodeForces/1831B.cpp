/*
6/13/2023

Notes: I struggled a lot with this problem, and couldn't even come up with the key idea that in merging two arrays, you can force the merged array to have any subset of 
array "a" be right next to any subset of array "b" (with these two subsets being somewhere in the middle of the whole array). You can sort of get to this idea by realizing 
that we want some sort of constructive algorithm that can instantly create the optimal merged array. If each move involves removing the front element of either array, then
we have to try and stop thinking in terms of the timing / sequence of these moves, and rather look at the big picture. If I want the "22222" from the array "34522222", we can
instantly get it by just removing the 3, 4, 5. This then applies to the second array and we realize we can always just remove the front numbers that we don't want, merge the 
two subsequences that we want, and then add everything else that remains. 

For some reason I thought that the case had to be:
  2 2 2 2 * * * *
  * * * * 2 2 2 2
  
Because then I could first choose the first four "*" from the second array, then choose the top 4 "2" from first array, and then bottom 4 "2" from second array. I should've
noticed that after removing the four "*" from the bottom array, it doesn't matter what happens next since I've removed all the unwanted numbers and am left with the 2 parts
from each array that I want to connect. 

After looking at the hint and understanding this solution, I implemented the solution horribly and there was first an error with how I implemented (forgot to add bound for 
while loop) and then there was time errors. The implementation shown in the editorial is much more clean so I tried to implement a solution based on that tutorial.
 
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
		vector<int> a(n);
		vector<int> b(n);;
		vector<int> consA(2*n);
		vector<int> consB(2*n);

		for(int i=0; i<n; i++) 
		{
			cin >> a[i];
		}
		for(int i=0; i<n; i++) 
		{
			cin >> b[i];
		}

		int p=0;
		for(int i=1; i<n; i++)
		{
			if(a[i]!=a[i-1])
			{
				consA[a[i-1]-1] = max(consA[a[i-1]-1], i-p);
				p=i;
			}
		}

		consA[a[n-1]-1] = max(consA[a[n-1]-1], n-p);

		p=0;
		for(int i=1; i<n; i++)
		{
			if(b[i]!=b[i-1])
			{
				consB[b[i-1]-1] = max(consB[b[i-1]-1], i-p);
				p=i;
			}
		}

		consB[b[n-1]-1] = max(consB[b[n-1]-1], n-p);
		
		int ans = 0;

		for(int i=0; i<2*n; i++)
		{
			ans = max(ans, consA[i]+consB[i]);
		}

		cout << ans << "\n";
		t--;
	}
}
