//link : https://cses.fi/problemset/task/2183/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

long minMissingSum(vector<int>& coins) {
	sort(coins.begin(), coins.end());
	long reach = 1;
	for(int coin: coins) {
		if(coin > reach)
			break;
		reach = reach + coin;
	}
	return reach;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<minMissingSum(arr)<<endl;
	return 0;
}