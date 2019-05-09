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
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);
    for(int i = 0; i < m; ++i) cin >> grid[i];
    int si = 0, sj = 0, ei = 0, ej = 0;
    int dirs[5] = {0, 1, 0, -1, 0};
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
            } else if (grid[i][j] == 'B') {
                ei = i;
                ej = j;
            }
        }
    }
    queue<pair<int, int>> frontier;
    frontier.push({si, sj});
    map<pair<int, int>, pair<int, int>> path;
    path[{si, sj}] = {-1, -1};
    grid[si][sj] = '#';
    bool has_path = false;
    while (!frontier.empty()) {
        auto & node = frontier.front();
        frontier.pop();
        int i = node.first, j = node.second;
        if (i == ei && j == ej) {
            // compute path
            string ans = "";
            int curi = ei, curj = ej;
            while (true) {
                auto pre = path[{curi, curj}];
                if (pre.first == -1 && pre.second == -1) {
                    break;
                } else {
                    if (pre.first - curi == 1) ans += 'U';
                    else if (pre.first - curi == -1) ans += 'D';
                    else if (pre.second - curj == 1) ans += 'L';
                    else ans += 'R';
                }
                curi = pre.first;
                curj = pre.second;
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n";
            cout << ans.length() << endl;
            cout << ans << endl;
            has_path = true;
            break;
        }
        for(int k = 0; k < 4; ++k) {
            int ni = i + dirs[k], nj = j + dirs[k + 1];
            if (0 <= ni && ni < m && 0 <= nj && nj < n && grid[ni][nj] != '#') {
                grid[ni][nj] = '#';
                path[{ni, nj}] = {i, j};
                frontier.push({ni, nj});
            }
        }

    }
    if (!has_path) cout << "NO\n";
    return 0;
}

