#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		long long n;
		cin >> n;
		vector<long long> nums(n);
		for(int i=0; i<n; i++) 
		{
			cin >> nums[i];
		}

		// unique returns pointer to new end of vector after duplicates are removed
		// also automatically removes the duplicates from the vector 
		n = unique(nums.begin(), nums.end()) - nums.begin();

		long long ans = n;

		for(int i=0; i+2<n; i++)
		{
			// basically subtracting the "middle" terms from the path where it's all increasing / decreasing
			if(nums[i]<nums[i+1] && nums[i+1]<nums[i+2]) ans--;
			if(nums[i]>nums[i+1] && nums[i+1]>nums[i+2]) ans--;
		}

		cout << ans << "\n";
		t--;
	}
}


/*
-----------------------------------------------------
MY ORIGINAL CODE THAT WORKS (AFTER THE INPUT SECTION)
-----------------------------------------------------
		bool up = false;
		for(int i=0; i<n-1; i++)
		{
			if(nums[i]<nums[i+1]) 
			{
				up = true;
				break;
			}
			else if(nums[i]>nums[i+1]) break;
		}
		long long upMax = 1;
		long long upMin = 0;
		long long downMax = 1;
		long long downMin = 0;
		long long counter = n;
		for(int i=1; i<n; i++)
		{
			if(up && nums[i]>=nums[i-1]) upMax = i;
			else if(!up && nums[i]<=nums[i-1]) downMax = i;
			else if(up && nums[i]<nums[i-1]) 
			{
				downMin = i-1;
				downMax = i;
				counter -= (upMax-upMin-1);
				up = false;
			}
			else if(!up && nums[i]>nums[i-1])
			{
				upMin = i-1;
				upMax = i;
				counter -= (downMax-downMin-1);
				up = true;
			}
		}

		if(up && nums[nums.size()-1]>=nums[nums.size()-2]) 
		{
			if(nums[upMax]==nums[upMin]) counter-=(upMax-upMin);
			else counter -= (upMax-upMin-1);
		}
		else if(!up && nums[nums.size()-1]<=nums[nums.size()-2]) 
		{
			if(nums[downMax]==nums[downMin]) counter-=(downMax-downMin);
			else counter -= (downMax-downMin-1);
		}

		cout << counter << "\n";
*/
