//link : https://cses.fi/problemset/task/1619/
//status: ACCEPTED

#include<bits/stdc++.h>
using namespace std;

// int maxCustomers(vector<vector<int>>& intervals) {
//     vector<vector<int>> A;
//     for (auto& v : intervals) {
//         A.push_back({v[0], 1});
//         A.push_back({v[1] + 1, -1});
//     }
//     int res = 0, cur = 0;
//     sort(A.begin(), A.end());
//     for (auto& v : A)
//         res = max(res, cur += v[1]);
//     return res;
// }

int maxCustomers(vector<vector<int>>& intervals) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto& el: intervals) {
        pq.push({el[0], 1});
        pq.push({el[1], -1});
    }
    int ans = 0, cur = 0;
    while(!pq.empty()) {
        cur += pq.top().second;
        pq.pop();
        ans = max(ans, cur);
    }
    return ans;
}

// int maxCustomers(vector<vector<int>>& intervals) {
//     map<int, int> A;
//     for (auto& v : intervals)
//         A[v[0]]++, A[v[1] + 1]--;
//     int res = 0, cur = 0;
//     for (auto& v : A)
//         res = max(res, cur += v.second);
//     return res;
// }

int main(void) {
    int n;
    cin>>n;
    int e, l;
    vector<vector<int>> entry;
    for(int i = 0; i < n; i++) {
        cin>>e>>l;
        entry.push_back({e, l});
    }
    cout<<maxCustomers(entry)<<endl;
    return 0;
}