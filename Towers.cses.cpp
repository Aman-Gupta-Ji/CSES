//link : https://cses.fi/problemset/task/1073/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

int minTowers(vector<int>& cubes, int n) {
	multiset<int> towers;
	multiset<int>:: iterator up;
	for(int cube: cubes) {
		up = towers.upper_bound(cube);
		if(up != towers.end())
			towers.erase(up);
		towers.insert(cube);
	}
	return towers.size();
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<minTowers(arr, n)<<endl;
	return 0;
}