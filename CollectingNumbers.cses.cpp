//link : https://cses.fi/problemset/task/2216/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

int rounds(vector<int>& arr, int n) {
	vector<pair<int, int>> ind(n);
	for(int i = 0; i < n; i++)
		ind[i] = make_pair(arr[i], i);
	sort(ind.begin(), ind.end());
	int count = 0;
	for(int i = 1; i < n; i++)
		if(ind[i].second < ind[i - 1].second)
			count++;
	return count + 1;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<rounds(arr, n)<<endl;
	return 0;
}