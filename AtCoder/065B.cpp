/* 
6/14/2023, https://atcoder.jp/contests/abc065/tasks/abc065_b 

Notes: Relatively straight forward problem.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, curId = 0;
	cin >> n;
	vector<int> nums(n);
	bool seen[n] = {false};
	for(int i=0; i<n; ++i) {cin >> nums[i]; nums[i]--;}

	int cost = 1;
	while(true)
	{
		if(seen[curId])
		{
			cout << "-1\n";
			break;
		}
		if(nums[curId] == 1) 
		{
			cout << cost << "\n";
			break;
		}
		seen[curId] = true;
		curId = nums[curId];
		cost++;
	}
}
