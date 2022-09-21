//link : https://cses.fi/problemset/task/2168/
//status: TLE

#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> checkNested(vector<vector<int>> range, int n) {
	vector<vector<bool>> res(2, vector<bool>(n, false));
	sort(range.begin(), range.end(), [](vector<int>& a, vector<int>& b) {
		if(a[0] == b[0])
			return a[1] > b[1];
		return a[0] < b[0];
	});
	int i, j;
	for(i = 0; i < n ; i++) {
		// cout<<range[i][0]<<" "<<range[i][1]<<" "<<range[i][2]<<endl;
		for(j = i - 1; j >= 0; j--) {
			if(range[i][1] <= range[j][1]) {
				res[1][range[i][2]] = true;
				res[0][range[j][2]] = true;
			}
		}
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