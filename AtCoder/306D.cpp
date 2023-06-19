/*
6/19/2023

Notes: I failed this problem in contest, and turns out the solution was through dp. Kind of hard since I've never learned dp / understood it but now it kinda makes sense. In
this code, dp[i][j] represents the maximum amount of "tastiness" at the ith course with a healthiness of j. For example, dp[0][0] = 0 because we have 0 tastiness on the first
course (0 based index) and we already know that the healthiness must be 0 on the first course (so dp[0][1] remains untouched as negative inf)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long> x(n), y(n);
	for(long long i=0; i<n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	long long dp[n+1][2];
	for(long long i=0; i<=n; ++i)
	{
		dp[i][0] = -4e18;
		dp[i][1] = -4e18;
	}

	dp[0][0] = 0;

	for(long long i=0; i<n; ++i)
	{
		if(x[i]==0)
		{
			dp[i+1][0] = max(dp[i][0], max(dp[i][0],dp[i][1])+y[i]);
		}else
		{
			dp[i+1][1] = max(dp[i][1], dp[i][0]+y[i]);
		}

		dp[i+1][0] = max(dp[i][0], dp[i+1][0]);
		dp[i+1][1] = max(dp[i][1], dp[i+1][1]);
	}
	
	cout << max(dp[n][0], dp[n][1]) << "\n";
}
