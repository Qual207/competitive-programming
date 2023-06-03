/*
Notes: The main reason I solved this (very quickly) is because I had done a very similar problem before (The Castle from USACO Training Pages), however I did this problem a 
while ago so I'm glad I was able to remember it so vividly. I initially had errors when submitting, but that was because I forgot to only run the DFS on values of the table
that are NOT EQUAL to 0 (I had to see the solution for realizing this part). This does matter because the 0s could basically serve as "connecting" points between two actual
"lakes". Also in the very beginning I forgot to mark the cells as visited after visiting them. I'm glad 
that I spotted the idea to this problem relatively quickly however. 

*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int table[1005][1005];
bool visited[1005][1005];
int sum = 0;
void dfs(int row, int col)
{
	if(visited[row][col]) return;

	visited[row][col] = true;
	sum += table[row][col];
	bool check = false;
	if(row+1<n && table[row+1][col]>0) 
	{
		dfs(row+1, col);
		check = true;
	}
	if(col+1<m && table[row][col+1]>0) 
	{
		dfs(row, col+1);
		check = true;
	}
	if(row-1>=0 && table[row-1][col]>0) 
	{
		dfs(row-1, col);
		check = true;
	}
	if(col-1>=0 && table[row][col-1]>0) 
	{
		dfs(row, col-1);
		check = true;
	}
	if(!check) return;
}

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		cin >> n >> m;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++) 
			{
				cin >> table[i][j];
				visited[i][j] = false;
			}
		}

		int ans = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(!visited[i][j] && table[i][j]!=0) 
				{
					sum = 0;
					dfs(i, j);
					ans = max(ans, sum);
				}
			}
		}

		cout << ans << "\n";
		t--;
	}
}
