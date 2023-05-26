#include <bits/stdc++.h>

using namespace std;

int main()
{
	int wx1, wx2, wy1, wy2;
	int ax1, ax2, ay1, ay2;
	int bx1, bx2, by1, by2;

	cin >> wx1 >> wy1 >> wx2 >> wy2 >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

	wx1*=2; wy1*=2; wx2*=2; wy2*=2; ax1*=2; ay1*=2; ax2*=2; ay2*=2; bx1*=2; by1*=2; bx2*=2; by2*=2;

	bool check = false;
	for(int i=wx1; i<=wx2; i++) // 11, 9
	{
		//check (i, ay1) and (i, ay2) and i, by1 and i, by2 
		if((i<ax1 || i>ax2 || wy1<ay1 || ay2<wy1) && (i<bx1 || i>bx2 || wy1<by1 || by2<wy1))
		{
			cout << "YES\n";
			check = true;
			break;
		}
		if((i<ax1 || i>ax2 || wy2<ay1 || ay2<wy2) && (i<bx1 || i>bx2 || wy2<by1 || by2<wy2))
		{
			cout << "YES\n";
			check = true;
			break;
		}
	}
	if(!check)
	{
	for(int j=wy1; j<=wy2; j++)
	{
		if((j<ay1 || j>ay2 || wx1<ax1 || ax2<wx1) && (j<by1 || j>by2 || wx1<bx1 || bx2<wx1))
		{
			cout << "YES\n";
			check = true;
			break;
		}
		if((j<ay1 || j>ay2 || wx2<ax1 || ax2<wx2) && (j<by1 || j>by2 || wx2<bx1 || bx2<wx2))
		{
			cout << "YES\n";
			check = true;
			break;
		}
	}
	}
	if(!check) cout << "NO\n";
}
