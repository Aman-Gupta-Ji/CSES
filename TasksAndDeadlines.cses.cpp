//link : https://cses.fi/problemset/task/1630/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

long reward(vector<pair<int, int>>& tasks) {
	sort(tasks.begin(), tasks.end());
	long t = 0, r = 0;
	for(pair<int, int>& task: tasks) {
		t += task.first;
		r += task.second - t;
	}
	return r;
}

int main(void) {
	int n;
	cin>>n;
	vector<pair<int, int>> tasks(n);
	for(int i = 0; i < n; i++) 
		cin>>tasks[i].first>>tasks[i].second;
	cout<<reward(tasks)<<endl;
	return 0;
}