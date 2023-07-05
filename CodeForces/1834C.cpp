/*
7/4/2023

Notes: I found the intended solution right away, but forgot that you had to take the min of the two different values. My initial approach ignored the case where fCount==rCount.
*/

#include <bits/stdc++.h>

using namespace std;

/*thoughts: 

we can just have alice aim to flip all the chars in one string until
it either matches the other or is equal to the reverse of that. That's the
optimal way that will give the total duration.

also there's 2 extra cases? if S=T, we're done. If S = rev(T), we just output 2

it's about finding which one to go for - either make T = S or T = rev(S)

*/

int main()
{
	int test;
	cin >> test;
	while(test>0)
	{
		int n; cin >> n;
		string s, t; cin >> s >> t;

		int fCount = 0;
		int rCount = 0;

		for(int i=0; i<n; ++i)
		{
			if(s[i]==t[i]) fCount++;
			if(s[n-i-1]==t[i]) rCount++;
		}

		if(fCount==n) cout << "0\n";
		else if(rCount==n) cout << "2\n";
		else if(fCount==0 && rCount==0)
		{
			cout << n*2-1 << "\n";
		}
		else cout << min(2*(n-fCount)-(n-fCount)%2, 2*(n-rCount)-(1-(n-rCount)%2)) << "\n";
		
		/*
		else if(fCount>=rCount)
		{
			cout << 2*(n-fCount)-(n-fCount)%2 << "\n";
			//n-fCount
			//if((n-fCount)%2==0) cout << 2*(n-fCount) << "\n";
			//else cout << (n-fCount)+(n-fCount-1) << "\n";
		}
		else
		{
			cout << 2*(n-rCount)-(1-(n-rCount)%2) << "\n";
			//if((n-rCount)%2==1) cout << (n-rCount)*2 << "\n";
			//else cout << (n-rCount)*2-1 << "\n";
		}
		*/
		test--;
	}
}
