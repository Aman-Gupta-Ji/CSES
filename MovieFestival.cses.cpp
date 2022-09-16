//link : https://cses.fi/problemset/task/1629/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

int maxMovies(vector<pair<int, int>>& movie) {
	int n = movie.size();
	sort(movie.begin(), movie.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});
	int maxMovies = 0;
	int t = 0;
	for(auto& m: movie) {
		if(t <= m.first) {
			// cout<<m.first<<" "<<m.second<<endl;
			maxMovies++;
			t = m.second;
		}
	}
	return maxMovies;
}

int main(void) {
	int s, e, n;
	cin>>n;
	vector<pair<int, int>> movie(n);
	for(int i = 0; i < n; i++) {
		cin>>s>>e;
		movie[i] = {s, e};
	}
	cout<<maxMovies(movie)<<endl;
	return 0;
}