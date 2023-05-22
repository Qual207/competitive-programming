// This is essentially the code shown in the guide solution. Great usage of sets.

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("evolution.in");
	ofstream fout("evolution.out");
	int n;
	fin >> n;
	set<string> all_traits_set;
	vector<set<string>> cows;
	for(int i=0; i<n; i++)
	{
		int k;
		fin >> k;
		set<string> temp;
		for(int j=0; j<k; j++)
		{
			string s;
			fin >> s;
			temp.insert(s);
		}
		cows.push_back(temp);
		all_traits_set.insert(temp.begin(), temp.end());
	}

	vector<string> all_traits(all_traits_set.begin(), all_traits_set.end());

	bool check = true;
	for(int i=0; i<all_traits.size(); i++)
	{
		for(int j=i+1; j<all_traits.size(); j++)
		{
			bool only_a = false;
			bool only_b = false;
			bool both = false;
			for(const set<string> &c: cows)
			{
				bool has_a = c.count(all_traits[i]);
				bool has_b = c.count(all_traits[j]);

				if(has_a && !has_b) only_a = true;
				else if(!has_a && has_b) only_b = true;
				else if(has_a && has_b) both = true;
			}

			if(only_a && only_b && both) 
			{
				check = false;
				break;
			}
		}
		if(!check) break;
	}

	if(check) fout << "yes\n";
	else fout << "no\n";
}
