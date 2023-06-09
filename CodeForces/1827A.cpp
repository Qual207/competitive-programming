/*
6/8/2023

Notes: This was a very nice solve. I'm happy that I was able to analyze the test cases very well and come up with a good solution without any assistance. Maybe it was cause
this problem is slightly involved with combo. I did, however, have two troubles: 1) issues with while loop never ending. 2) issues with integer overflow

For 1) my while loop assumed that there would always be a number in the first array "a" that would be larger than any number in the second array "b". Obviously this is not
the case, but I overlooked it. Have to be careful with while loops, and understand what exactly I'm doing with them to help spot errors.

For 2) I forgot about the random "mod 10^9+7" in the problem, and should have implemented that in the for loop calculating product rather than placing it at the very end 
(to prevent overflow).

*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{

		t--;
		int n;
		cin >> n;
		vector<long long> first(n);
		vector<long long> second(n);

		for(int i=0; i<n; i++)
		{
			cin >> first[i];
		}

		for(int i=0; i<n; i++)
		{
			cin >> second[i];
		}

		sort(first.begin(), first.end());
		sort (second.begin(), second.end());

		//to count "y"
		vector<long long> y(n);
		int curIndex = 0;
		for(int i=0; i<n; i++)
		{
			while(second[i]>=first[curIndex] && curIndex<n) 
			{
				curIndex++;
			}
			y[i] = n-curIndex;
		}

		sort(y.begin(), y.end());
		long long product = 1;
		for(int i=0; i<n; i++)
		{
			product = product*(y[i]-i)%MOD;
		}

		if(product<=0) cout << "0\n";
		else cout << product<< "\n";
	}
}
