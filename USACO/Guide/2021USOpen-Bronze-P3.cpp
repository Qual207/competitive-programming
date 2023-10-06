/*
10/6/2023
Note: My original idea was to go through each cow starting from top to bottom left to right, and just mark every G that the
cow could eat. However I gave up because the same pair of cows could be used for multiple G's, and I didn't know how to avoid
this overcount. Maybe store in set?

This solution is better: You have to first observe that if the formation is like "CGC" we can in
*/

#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<string> G(1000);

bool exists_cow(int i, int j) { 
	if(0 <= i && i < N && 0 <= j && j < M && G[i][j] == 'C') return true;
  else return false;
}

int main() {
	cin >> N >> M;
  for (string& row: G) cin >> row;

	set<vector<pair<int,int>>> pairs;
	int ans = 0;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) if (G[i][j] == 'G') {
			vector<pair<int,int>> v;
			int dx[4] = {1,0,-1,0};
			int dy[4] = {0,1,0,-1};
			for (int d = 0; d < 4; ++d) {
				if (exists_cow(i+dx[d],j+dy[d])) v.emplace_back(i+dx[d],j+dy[d]);
			}
			if (v.size() > 2) {
				++ans;
				continue;
			}
			if (v.size() == 2) {
				sort(v.begin(), v.end());
				pairs.insert(v);
			}
		}
	cout << pairs.size()+ans << "\n";
}
