/*
9/3/2023

Notes: Knew that the optimization had to do with getting as many 9s to correspond with 0s. Something I should have considered
is that the max you can get at each digit position is 9-0 = 9 so I might as well just try and get two numbers where one number
is 99999 and the other is 00000. I got confused / discouraged after seeing the various different types of bounds. 

It makes sense to think that once you've found the point at which the two numbers differ, you can change everything AFTER that point.
For example, if we ahve 12344 and 123987 then we can change the 44 part (only by increasing it) and the 87 part (only by decreasing it)
and the most optimal way to do this is to get the 44 part --> 99 and the 87 part --> 00. 

*/

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
