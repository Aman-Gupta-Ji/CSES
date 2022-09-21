//link : https://cses.fi/problemset/task/2162/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

void eliminateAll(list<int>& child, bool start1) {
	if(child.empty())
		return;
	auto be = child.begin();
	if(start1)
		be++;
	while(true) {
		if(be == child.end()) {
			eliminateAll(child, false);
			break;
		}
		auto c = be;
		cout<<*c<<" ";
		be++;
		child.erase(c);
		if(be == child.end()) {
			eliminateAll(child, true);
			break;
		}
		be++;
	}
}

int main(void) {
	int n;
	cin>>n;
	list<int> child;
	for(int i = 1; i <= n; i++)
		child.push_back(i);
	eliminateAll(child, true);
	return 0;
}