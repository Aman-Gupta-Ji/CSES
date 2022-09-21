//link : https://cses.fi/problemset/task/1194/
//status: TLE

#include<bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1001][1001];
 
string dirC = "RDLU";
int dir[] = {0, 1, 0, -1, 0};
 
pair<int, string> dfs(vector<string>& grid, int i, int j, int len) {
    // 0 means success
    if(i < 0 || i >= n || j < 0 || j >= m)
        return make_pair(-1, "O");
 
    if(grid[i][j] == '#' || visited[i][j])
        return make_pair(-1, "O"); // -ve for wall
 
    if(grid[i][j] == 'M')
        return make_pair(1, "O"); // +ve distance for Moster
 
    len++;
    int d = -1;
    string res = "O";
 
    int ni, nj;
    char s;
 
    pair<int, string> go;
 
    visited[i][j] = true;
    bool can = true;
 
    for(int k = 0; k < 4; k++) {
        ni = i + dir[k];
        nj = j + dir[k + 1];
        s = dirC[k];
        go = dfs(grid, ni, nj, len);
        if(go.first < 0)
            continue;
        if(go.first == 0) {
            if(can && (d != 0 || res.length() > go.second.length() + 1)) {
                d = 0;
                res = s + go.second;
            }
        }
        else if(go.first < len) {
            if(d <= 0)
                d = go.first + 1;
            else
                d = min(d, go.first + 1);
            // cout<<len<<" -> "<<i<<" "<<j<<" : "<<d<<endl;
            res = "O";
            can = false;
        }
    }
 
    visited[i][j] = false;

    if(d <= 0 && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
        return make_pair(0, ""); // reached the destination

    return make_pair(d, res);
}
 
pair<int, string> getPath(vector<string>& grid) {
    int i, j;
    memset(visited, false, sizeof(visited));
 
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(grid[i][j] == 'A')
                return dfs(grid, i, j, 0);
 
    return make_pair(1, "");
}
 
int main(void) {
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin>>grid[i];
 
    pair<int, string> res = getPath(grid);
 
    if(!res.first) {
        cout<<"YES"<<endl;
        cout<<res.second.length()<<endl;
        cout<<res.second<<endl;
    }
    else
        cout<<"NO"<<endl;
 
    return 0;
}