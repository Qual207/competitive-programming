/*
6/27/2023

Notes: Didn't solve this problem, gave up too early. Should of spent more time looking into how the "or" operator works. Key idea was that you can use any book such that 
the book doesn't have any "1" in a position where x has a "0". 

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t>0)
	{
		int n, x;
		cin >> n >> x;

		int s = 0;
		int a[n];
		for(int i=0; i<3; ++i)
		{
      //must input each row separately so that once we reach a book that doesn't work, we can break out of this row and start inputting the next row.
			for(int j=0; j<n; ++j) 
			{
				cin >> a[j];
			}
				
			for(int j=0; j<n; ++j)
			{
				if((x|a[j]) != x) break;
				s |= a[j]; 
			}
		}

		if(s==x) cout << "YES\n";
		else cout << "NO\n";
		t--;
	}

}
