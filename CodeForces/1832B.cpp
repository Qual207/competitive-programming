/*
Notes: I wasn't able to come up with a solution to this problem, and had to rely on the tutorial solution.

My thought process: I ran out of ideas after trying to tackle the issue that greedy did not work. Because of this, I couldn't think about 
how to come up with a non brute force solution since how would you know when to take a maximum vs two minimums? 

I couldn't come up with the connection that you can only make two moves: remove maximum, or two minimums and it doesn't matter the order that you do these moves. 
I didn't think to generalize the process because with each case, you just remove a certain amount of two minimums and a certain amount of maximums and you are left with a
brute forcable middle section.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		int n, k;
		cin >> n >> k;
		vector<long long> arr(n);
		for(int i=0; i<n; i++) 
		{
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		long long totalSum = 0;
		for(int i=2*0+1-1; i<=(n-(k-0))-1; i++)
		{
			totalSum += arr[i];
		}

		long long answer = totalSum;
		for(int m=1; m<=k; m++)
		{
			totalSum += arr[n-(k-m)-1];
			totalSum -= (arr[2*m-1] + arr[2*m-2]);
			answer = max(answer, totalSum);
		}

		cout << answer << "\n";

		t--;
	}
}
