/*
6/16/2023

Notes: I overthought this problem and was actually quite excited when I originally found what I thought was the intended solution. I implemented it and got some strange errors
with scientific notation but after I fixed I got AC. I was very shocked when I read the editorial - kinda dumb for not seeing this sneaky solution.

The key is to limit yourself to 2 cases: either you have too many coins or you have too many desserts. Having too many coins is easy, because that means you can buy all the 
desserts which is just 2^k. But if you have too many desserts, then you're limited by how many coins you have. Luckily, WE KNOW THAT WITH N COINS, EVERY SINGLE AMOUNT OF COINS
SPENT FROM 0 THROUGH N CAN BE REPRESENTED BY A UNIQUE COMBINATION OF POWERS OF 2. 

*/

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		int n, k;
		cin >> n >> k;
		k = min(k, 30);
		cout << min(n+1, (1<<k)) << "\n";

		/*
    ------------------- OLD CODE THAT I ORIGINALLY WROTE -------------------
  
		long long coins = n;
		long long counter = 0;
		while(n>1)
		{
			n/=2;
			counter++;
		}

		long long maxCoins = min(counter, k-1);

		if(pow(2, maxCoins+1)<=coins) ++maxCoins;

		long long answer = 0;

		if(maxCoins == k) cout << fixed << setprecision(0) << pow(2, k) << "\n";
		else
		{
			while(coins>=0)
			{
				coins -= pow(2, maxCoins);
				answer += pow(2, maxCoins);

				long long temp = 0;
				long long copy = coins;
				while(coins>1)
				{
					coins/=2;
					temp++;
				}

				maxCoins = temp;
				coins = copy;
			}

			cout << fixed << setprecision(0) << answer << "\n";
		}
    ------------------- OLD CODE THAT I ORIGINALLY WROTE -------------------
		*/

		t--;
	}
}
