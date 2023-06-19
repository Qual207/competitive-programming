/*
6/19/2023

Notes: This was a good solve (kind of an easier problem though since 1000 rated), and my solution was the same as the one in the tutorial.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		int q;
		cin >> q;
		vector<int> nums;
		int curCount = 0;
		for(int i=0; i<q; ++i)
		{
			int x;
			cin >> x;
			if(i==0) {nums.push_back(x); cout << "1"; continue;}

			if(x<nums[nums.size()-1]) curCount++;
			if(curCount==2) 
			{
				cout << "0";
				if(x<nums[nums.size()-1]) curCount--;
			}
			else if(curCount==1 && nums[0]<x)
			{
				cout << "0";
				if(x<nums[nums.size()-1]) curCount--;
			}
			else {cout << "1"; nums.push_back(x);}
		}

		cout << "\n";

		t--;
	}
}
