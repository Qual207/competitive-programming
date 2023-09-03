#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		string a, b;
		cin >> a >> b;
		if(a==b) cout << "0\n";
		else 
		{
			string a2 = string(b.length()-a.length(), '0')+a;
			int k;
			int comSum = 0;
			for(int i=0; i<b.length(); i++)
			{
				if(a2[i]!=b[i])
				{
					k = i; 
					break;
				}
			}
			cout << max(b[k]-a2[k], a2[k]-b[k])+9*(b.length()-1-k) << "\n";
		}

		t--;
	}
}
