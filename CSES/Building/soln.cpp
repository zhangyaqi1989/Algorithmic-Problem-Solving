/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int maxArea(vector<int> & hs) {
    stack<int> stk;
    int mx = 0, n = hs.size();
    for(int i = 0; i < n; ++i) {
        while(!stk.empty() && hs[i] < hs[stk.top()]) {
            int h = hs[stk.top()];
            stk.pop();
            int pre = stk.empty() ? -1 : stk.top();
            int w = i - pre - 1;
            mx = max(mx, w * h);
        }
        stk.push(i);
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);
    for(int i = 0; i < m; ++i) cin >> grid[i];
    vector<int> dp(n + 1, 0);
    int mx = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            dp[j] = grid[i][j] == '*' ? 0 : dp[j] + 1;
        }
        mx = max(mx, maxArea(dp));
    }
    cout << mx << endl;
    return 0;
}

