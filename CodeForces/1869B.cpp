/*
10/7/2023
Needed to read hint + part of sol to get this problem. There are a couple keys to this problem: 
1) without any major cities, max dist is always just abs(x1-x2) + abs(y1-y2) where 1 and 2 are the start and end cities.
2) if there are major cities, find the ones closest to ur start and end points. It doesn't matter if they end up giving 
longer dist than if u didn't use major cities since at the end u can just check for that. 
2.5) You will only ever need at most 2 major cities because if we went through 3 major cities we could just directly go from
the first one to the third one.
3) If the major city closest to starting city is X and the major city closest to end city is Y, we can loop through these
independent of each other. This is because even if X=Y this is the same as not going to a major city at all since your just
going from start --> X --> end.
4) Also size errors with long long 

I had to realize that the major cities used don't need to be in the "rectangle" fence within the start and end points. 
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t>0)
	{
		long long n, k, a, b;
		cin >> n >> k >> a >> b;
		a--; b--;

		pair<long long, long long> cities[n];
		for(int i=0; i<n; i++) cin >> cities[i].first >> cities[i].second;

		long long dist1 = 4000000000, dist2 = 4000000000;
		for(int i=0; i<k; i++)
		{
			dist1 = min(dist1,llabs(cities[i].first-cities[a].first)+llabs(cities[i].second-cities[a].second));
			dist2 = min(dist2, llabs(cities[i].first-cities[b].first)+llabs(cities[i].second-cities[b].second));
		}

		cout << min(llabs(cities[a].first-cities[b].first)+llabs(cities[a].second-cities[b].second), dist1+dist2) << "\n";
		t--;
	}
}
