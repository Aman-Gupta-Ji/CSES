//link : https://cses.fi/problemset/task/1621/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin>>n;
	set<int> dist;
	int i, a;
	for(i = 0; i < n; i++) {
		cin>>a;
		dist.insert(a);
	}
	cout<<dist.size()<<endl;
	return 0;
}