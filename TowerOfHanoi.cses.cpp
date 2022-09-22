//link : https://cses.fi/problemset/task/2165
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

void simulate(int n, int s, int e, int m) {
	if(n == 0)
		return;
	simulate(n - 1, s, m, e);
	cout<<s<<" "<<e<<endl;
	simulate(n - 1, m, e, s);
}

int main(void) {
	int n;
	cin>>n;
	cout<<pow(2, n) - 1<<endl;
	simulate(n, 1, 3, 2);
	return 0;
}