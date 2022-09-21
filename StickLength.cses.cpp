//link : https://cses.fi/problemset/task/1074/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

long conversionCost(vector<int>& arr, int target) {
	long cost = 0;
	for(int a: arr)
		cost += abs(a - target);
	return cost;
}

long minCost(vector<int>& arr, int n) {
	sort(arr.begin(), arr.end());
	if(n % 2 == 0) {
		double median = (arr[n / 2] + arr[(n / 2) - 1]) / 2.0;
		if(floor(median) == ceil(median))
			return conversionCost(arr, median);
		return min(conversionCost(arr, floor(median)), 
					conversionCost(arr, ceil(median)));
	}
	return conversionCost(arr, arr[n / 2]);
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<minCost(arr, n)<<endl;
	return 0;
}