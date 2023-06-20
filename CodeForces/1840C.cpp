/*
6/20/2023

Notes: I had the same exact solution as the intended one, but for some reason I messed the implementation up really badly. First thing is that I have this bad habit of 
wanting to add in "markers" to represent (in this example) where all the positions of values that exceed the temp limit are located. My thought process is that I can use thes
markers to determine the length between consecutive ones. However, it's much easier to just keep a running total of your current length of "good" values. The moment you get a
bad value, then just do what you want with the current length and then make sure to reset it to 0. There's only one side case with this which is if you end on a length of "good"
values with no "bad" value to tell you that the length has stopped. In this case you just have to add in at the end (so check if the length is in fact >=k and then update sum)

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while(t>0)
	{
		long long n, k, q;
		cin >> n >> k >> q;
		vector<long long> nums(n);

		long long len = 0;
		long long sum = 0;
		for(long long i=0; i<n; ++i) 
		{
			cin >> nums[i];
			if(nums[i]<=q) len++;
			else
			{
				if(len>=k)
				{
					sum += (len-k+2)*(len-k+1)/2;
				}
				len = 0;
			}
		}

		if(len>=k)
		{
			sum += (len-k+2)*(len-k+1)/2;
		}

		cout << sum << "\n";
		t--;
	}
}
