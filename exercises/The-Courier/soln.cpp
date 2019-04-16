/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int dist[101][101];
int works[5][3];
int locations[13][2];
int dp[13][1 << 13];
int limit, cities, home;

// compute distance from i to j
int cdist(int i, int j) {
    if (i == j) return 0;
    int u = locations[i][1], v = locations[j][0];
    return dist[u][v];
}

int solve(int idx, int mask);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int case_idx = 0; case_idx < T; ++case_idx) {
        int n, m, origin;
        cin >> n >> m >> origin;
        memset(dist, 0, sizeof(dist));
        for(int i = 0; i < m; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            dist[u][v] = d;
            dist[v][u] = d;
        }

        int z;
        cin >> z;
        // cout << z << endl;
        memset(works, 0, sizeof(works));
        int parcels = 0;
        for(int i = 0; i < z; ++i) {
            int u, v, b;
            cin >> u >> v >> b;
            // cout << u << " " << v << " " << b << endl;
            works[i][0] = u;
            works[i][1] = v;
            works[i][2] = b;
            parcels += b;
        }

        // Floyd-Warshall algorithm
        // 1. initialize
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (i == j) dist[i][j] = 0;
                else if (dist[i][j] == 0) {
                    dist[i][j] = INF;
                }
            }
        }
        // 2. F-W
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int route = 0;
        for(int i = 0; i < z; ++i) {
            int u = works[i][0], v = works[i][1], b = works[i][2];
            // cout << u << " " << v << " " << dist[u][v] << endl;
            route += dist[u][v] * b;
        }

        memset(locations, 0, sizeof(locations));
        int shift = 0;
        // put home in the zero index
        locations[shift][0] = origin;
        locations[shift][1] = origin;
        home = shift;
        ++shift;
        for(int i = 0; i < z; ++i) {
            int u = works[i][0], v = works[i][1], b = works[i][2];
            for(int j = 0; j < b; ++j) {
                locations[shift][0] = u;
                locations[shift][1] = v;
                ++shift;
            }
        }

        /*
        for(int i = 0; i < parcels + 1; ++i) {
            cout << locations[i][0] << " " << locations[i][1] << endl;
        }
        */

        // TSP: bitmask + DP
        cities = parcels + 1;
        limit = (1 << cities) - 1;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 1);
        cout << ans + route << endl;
    }

    return 0;
}

int solve(int idx, int mask) {
    if (mask == limit) return cdist(home, idx);
    if (dp[idx][mask] != -1) return dp[idx][mask];
    int ret = INT_MAX;
    for(int i = 0; i < cities; ++i) {
        if ((mask & (1 << i)) == 0) {
            int new_mask = mask | (1 << i);
            ret = min(ret, solve(i, new_mask) + cdist(i, idx));
        }
    }
    return dp[idx][mask] = ret;
}

