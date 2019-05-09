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
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for(int i = 0; i < n; ++i) cin >> prices[i];
    for(int i = 0; i < n; ++i) cin >> pages[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // dp[i][j] max pages with first i items and w weights
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= x; ++j) {
            if (prices[i - 1] <= j) {
                dp[i][j] = max(pages[i - 1] + dp[i - 1][j - prices[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}

