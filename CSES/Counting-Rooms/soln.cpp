/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * April 2019
 */
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string> & grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '#') return;
    grid[i][j] = '#';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);
    for(int i = 0; i < m; ++i) cin >> grid[i];
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                dfs(grid, i, j);
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
