/*
6/15/2023

Notes: Had the right idea but after implementing it failed so I gave up. The solution is similar to what I was going for though. After all operations are finished, the result
is always in the form "WWW...WBBB...B" where all the W chars are on the left and all the B chars are on the right. Thus, we look at the positions of each W to judge how many
operations it will take for the W to reach the left. However, you have to add in to account the previous W's because they will already take up spots on the left.

Actually now that I think about it, I had the exact same solution as the intended one except I thought in terms of how many "B" chars there were and so I implemented 
differently and it was harder. 
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	long long count = 0;
	long long wCount = 0;
	for(int i=0; i<s.length(); ++i)
	{
		if(s[i]=='W')
		{
			count += i - wCount;
			wCount++;
		}
	}

	cout << count << "\n";
}
