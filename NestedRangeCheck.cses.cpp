//link : https://cses.fi/problemset/task/2168/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> checkNested(vector<vector<int>> range, int n) {
	vector<vector<bool>> res(2, vector<bool>(n, false));
	sort(range.begin(), range.end(), [](vector<int>& a, vector<int>& b) {
		if(a[0] == b[0])
			return a[1] > b[1];
		return a[0] < b[0];
	});
	
	int maxe = 0;
	for(int i = 0; i < n ; i++) {
		if(range[i][1] <= maxe)
			res[1][range[i][2]] = true;
		maxe = max(maxe, range[i][1]);
	}

	int mine = INT_MAX;
	for(int i = n - 1; i >= 0; i--) {
		if(range[i][1] >= mine)
			res[0][range[i][2]] = true;
		mine = min(mine, range[i][1]);
	}
	
	return res;
}

int main(void) {
	int n;
	cin>>n;
	int x, y;
	vector<vector<int>> range(n);
	for(int i = 0; i < n; i++) {
		cin>>x>>y;
		range[i] = {x, y, i};
	}
	vector<vector<bool>> res = checkNested(range, n);
	for(vector<bool>& r: res) {
		for(bool b: r)
			cout<<b<<" ";
		cout<<endl;
	}
	return 0;
}