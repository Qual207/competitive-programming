/*
6/18/2023

Notes: Quite unfortunate that I was unable to solve this problem. It makes sense though - we know that no matter what, if you see a '<' sign, then the next value is 
guaranteed to be at least one more than the previous value. However, the same holds with '>' signs, in which the previous value is guaranteed to be at least one more than the
current value. So, you can just go both ways in which the second time you go backwards and check which condition forces a larger value (as that's the only way both conditions 
are satisfied).

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> nums(s.length()+1);

	for(int i=0; i<s.length(); ++i)
	{
		if(s[i]=='<') nums[i+1] = nums[i]+1;
	}

	for(int i=s.length(); i>=0; --i)
	{
		if(s[i]=='>') nums[i] = max(nums[i], nums[i+1]+1);
	}

	cout << accumulate(nums.begin(), nums.end(), 0ll) << "\n";
}
