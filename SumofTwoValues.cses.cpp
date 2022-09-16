//link : https://cses.fi/problemset/task/1640/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
	int n = arr.size();
	vector<pair<int,int>> pos(n);
	for(int i = 0; i < n; i++)
		pos[i] = {arr[i], i + 1};
	sort(pos.begin(), pos.end());
	int l = 0, r = n - 1, sum;
	while(l < r) {
		sum = pos[l].first + pos[r].first;
		if(sum == target)
			return {pos[l].second, pos[r].second};
		else if(sum < target)
			l++;
		else
			r--;
	}
	return {};
}

int main(void) {
	int n, x;
	cin>>n>>x;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	vector<int> res = twoSum(arr, x);
	if(!res.size())
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<res[0]<<" "<<res[1]<<endl;
	return 0;
}