//link : https://cses.fi/problemset/task/1643/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

long maxSubarray(vector<int>& arr) {
	int n = arr.size();
	long global = arr[0], local = 0;
	for(int i = 0; i < n; i++) {
		local += arr[i];
		global = max(global, local);
		if(local < 0)
			local = 0;
	}
	return global;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<maxSubarray(arr)<<endl;
	return 0;
}