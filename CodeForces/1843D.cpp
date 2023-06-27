/*
6/27/23

Notes: Did not get this one in contest, but I had the right idea. In contest I arrived to the point where I knew I had to do dfs on the tree and then just multiply the values,
but I was too lazy to implement the dfs and honestly didn't know how to. The dfs works likes this: for each point, go through all its children except the one connected above it
and then add the count value of those children to itself. But obv we don't know the count value so we have to run dfs on those children etc. This search ends when you arrive at
the bottom leafs which only have one edge connected to a vertex that is above it, so the parameters we take in dfs are v: the current vertex and p: the original parent vertex
that this vertex branched out from.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<long long> cnt;

void dfs(int v, int p)
{
	if(tree[v].size()==1 && tree[v][0]==p)
	{
		cnt[v] = 1;
	}
	else
	{
		for(auto x: tree[v])
		{
			if(x!=p)
			{
				dfs(x, v);
				cnt[v]+=cnt[x];
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		int n;
		cin >> n;

		tree.assign(n, vector<int>());

		for(int i=0; i<n-1; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}

		cnt.assign(n, 0);

    //we run dfs starting on the earliest vertex (0 since this is 0-based indexing) and then we set the "parent" vertex to any impossible number such that tree[0][0] will never
    equal to it
		dfs(0, -12389);

		int q;
		cin >> q;
		for(int i=0; i<q; ++i)
		{
			int c, d;
			cin >> c >> d;
			c--; d--;

			cout << (long long) cnt[c]*cnt[d] << "\n";
			
		}

		t--;
	}
}
