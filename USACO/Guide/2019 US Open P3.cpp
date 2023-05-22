#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("evolution.in");
	ofstream fout("evolution.out");
	int n;
	fin >> n;
	vector<vector<string>> traits;
	for(int i=0; i<n; i++)
	{
		int k;
		fin >> k;
		vector<string> temp(k);
		for(int j=0; j<k; j++) fin >> temp[j];
		traits.push_back(temp);
	}

	bool check = true;
	for(int i=0; i<n; i++)
	{
		if(traits[i].size()>1)
		{
			int count = 0;
			for(int j=0; j<traits[i].size(); j++)
			{
				for(int k=0; k<n; k++)
				{
					if(traits[k].size()==1 && traits[k][0]==traits[i][j])
					{
						count++;
					}
					if(count>1)
					{
						check = false;
						break;
					}
				}
				if(count>1)
				{
					check = false;
					break;
				}
			}
		}
	}

	if(check) fout << "yes\n";
	else fout << "no\n";
}
