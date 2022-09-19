//link : https://cses.fi/problemset/task/1163/
//status: TLE

#include<bits/stdc++.h>
using namespace std;

pair<int, int> maxdiff(map<int, int>& dark) {
	int d = -1;
	pair<int, int> gret;
	// cout<<"get max"<<endl;
	for(auto& e: dark) {
		// cout<<e.first<<" "<<e.second<<endl;
		if(d < e.second - e.first) {
			d = e.second - e.first;
			gret = e;
		}
	}
	return gret;
}

vector<int> maxDist(vector<int>& arr, int s, int n) {
	map<int, int> dark;
	dark[0] = s;
	for(int i = 0; i < n; i++) {
		auto el = dark.upper_bound(arr[i]);
		el--;
		dark[arr[i]] = el->second;
		el->second = arr[i];
	}
	pair<int ,int> maxe = maxdiff(dark);
	int maxd = maxe.second - maxe.first;
	vector<int> res(n);
	for(int i = n - 1; i >= 0; i--) {
		res[i] = maxd;
		auto el = dark.find(arr[i]);
		auto prev = el;
		--prev;
		prev->second = el->second;
		dark.erase(el);
		maxd = max(maxd, prev->second - prev->first);
	}
	return res;
}

int main(void) {
	int s, n;
	cin>>s>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	vector<int> res = maxDist(arr, s, n);
	for(int p: res)
		cout<<p<<" ";
	cout<<endl;
	return 0;
}