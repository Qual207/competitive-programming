/*
10/8/2023
Solved
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t>0)
	{
		int l, r; cin >> l >> r;
		if(r<4) cout << "-1\n";
		else if(l==r && l%2!=0)
		{
			bool check = true;
			double x = (double) r;
			for(int j=3; j<=sqrt(x); j++)
			{
				if(r%j==0)
				{
					cout << j*(r/j-1) << " " << j << "\n";
					check = false;
					break;
				}
			}
			if(check) cout << "-1\n";
		} 
		else
		{
			int i;
			for(i=r; i>=l; i--)
			{
				if(i%2==0) break;
			}
			cout << i/2 << " " << i/2 << "\n";
		}
		t--;
	}
}
