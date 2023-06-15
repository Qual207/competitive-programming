/*
6/14/2023

Notes: Very satisfying solve. Still need to come back to analyze this later but very happy that I solved this on my own. 

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
		pair<long long, long long> nums[n];

		for(int i=0; i<n; ++i)
		{
			cin >> nums[i].first >> nums[i].second;
		}

		sort(nums, nums+n);

		vector<int> markers;
		for(int i=1; i<n; ++i)
		{
			if(nums[i].first!=nums[i-1].first) markers.push_back(i-1);
		}
		markers.push_back(n-1);

		long long cost = 0;
		int numOn = 0;
		for(int i=0; i<markers.size(); ++i)
		{
			int temp = markers[i];
			if(i==0)
			{
				while(true)
				{
					if(temp<0 || nums[temp.first<=numOn) 
					{
						numOn = 0;
						break;
					}
					cost += nums[temp].second;
					numOn++;
					temp--;
				}
			}
			else
			{
				while(true)
				{
					if(temp<markers[i-1]+1 || nums[temp].first<=numOn)
					{
						numOn = 0;
						break;
					}
					cost += nums[temp].second;
					temp--;
					numOn++;
				}
			}
		}

		cout << cost << "\n";
		t--;
	}
}
