/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * April 2019
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int mod = 1e9 + 7;
    cin >> n >> m;
    set<pair<int, int>> traps;
    for(int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        traps.insert({--r, --c});
    }
    vector<int> dp(n, 0);
    // initialize the first row
    for(int j = 0; j < n; ++j) {
        if (traps.count({0, j})) {
            break;
        }
        dp[j] = 1;
    }
    for(int i = 1; i < n; ++i) {
        vector<int> temp(n, 0);
        if (traps.count({i, 0}) == 0) temp[0] = dp[0];
        for(int j = 1; j < n; ++j) {
            if (traps.count({i, j})) temp[j] = 0;
            else temp[j] = (temp[j - 1] % mod + dp[j] % mod) % mod;
        }
        swap(dp, temp);
    }
    cout << dp[n - 1] << endl;
    return 0;
}

