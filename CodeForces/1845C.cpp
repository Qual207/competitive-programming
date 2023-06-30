/*
6/30/2023

Notes: I took part in Edu CF R151, solved A and B (with a very last minute solve on B cuz of stupid logic error). For C, I kind of pushed this back because I thought it 
required dp which I'm not very familiar with. However, the tutorial mentioned that greedy works fine and greedy makes perfect sense to me so I implemented that and it actually
got AC. I guess now my goal is to learn dp since idk how popular it is in USACO but def very popular on CodeForces contests. Also maybe this means I need to start doing USACO
problems since they are kind of diff.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		string s, l, r; int m;
		cin >> s >> m >> l >> r;

		bool check = true;
		int curIndex = 0;
		for(int i=0; i<m; ++i)
		{
			for(int j=l[i]-'0'; j<=r[i]-'0'; ++j)
			{
				check = true;
				for(int k=curIndex; k<=s.length()-m+i; ++k)
				{
						if(s[k]-'0'==j)
						{
							//we've found a match, move on to the next one
							check = false;
							break;
						}
				}
        //if nothing matched, then we have one digit basically that could make a strong password since it fits all conditions
				if(check) {cout << "YES\n"; break;}
			}
      //something matched then...
			if(!check)
			{
        //go through all values in the acceptable range, find the one to the furthest right (originally I made a mistake where I just looped backwards and took the first value
        //in the range, but this doesn't account for repeated values. For example, 123123123 would fail this since if the range is from 1-3, the furthest right value for the first
        //digit is 3 but going backwards it would give you "1" at the 3rd to last index.
				int maxRight = -1;
				for(int bruh=l[i]-'0'; bruh<=r[i]-'0'; ++bruh)
				{
					for(int k=curIndex; k<=s.length()-m+i; ++k)
					{
						if(s[k]-'0'==bruh)
						{
							maxRight = max(maxRight, k);
							break;
						}
					}
				}
				curIndex = maxRight+1;
			}
			else break;
		}
		if (!check) cout << "NO\n";
		t--;
	}
}
