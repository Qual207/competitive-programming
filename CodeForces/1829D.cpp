/*
6/10/2023

Notes: This was a very quick solve. I drew out one testcase, realized I could draw it like a tree so I suspected dfs approach (plus I kinda looked at the tags). I had no 
errors with implementation which was good although I've kind of seen similar types of problems so maybe this is just a fluke. A better way to write the dfs function would be
to make it become a boolean function that returns either true or false. Since the function will have to return dfs(num/3) and dfs(num/3*2), I have to write:
  return (dfs(num/3) || dfs(num/3*2));
 which is something that I didn't know about previously.
*/

#include <bits/stdc++.h>

using namespace std;

int a, b;
bool check = false;
void dfs(int num)
{
	if(num==b)
	{
		check = true;
		return;
	}
	else if(num%3!=0 || num==0) return;
	else
	{
		dfs(num/3);
		dfs(num/3*2);	
	}
}

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		cin >> a >> b;
		check = false;
		dfs(a);
		if(check) cout << "YES\n";
		else cout << "NO\n";
		t--;
	}
}
