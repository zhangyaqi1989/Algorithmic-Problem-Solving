/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(vector<tuple<int, int, int>> & edges, int n, int src) {
    vector<long long> dist(n, LLONG_MAX);
    dist[src] = 0LL;
    vector<int> parents(n, -1);
    for(int i = 0; i < n - 1; ++i) {
        for(auto & edge : edges) {
            int u, v, c;
            tie(u, v, c) = edge;
            if (dist[u] != LLONG_MAX && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                parents[v] = u;
            }
        }
    }

    vector<int> path;

    for(auto & edge : edges) {
        int u, v, c;
        tie(u, v, c) = edge;
        if (dist[u] != LLONG_MAX && dist[u] + c < dist[v]) {
            set<int> seen;
            int cur = v;
            while (true) {
                path.push_back(cur + 1);
                if (seen.count(cur)) {
                    break;
                }
                seen.insert(cur);
                cur = parents[cur];
            }
            reverse(path.begin(), path.end());
            break;
        }
    }
    return path;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // vector<vector<pair<int, int>>> graph(n);
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        edges.push_back({u, v, c});
    }

    bool has = false;
    for(int i = 0; i < n; ++i) {
        vector<int> path = bellman_ford(edges, n, i);
        if (!path.empty()) {
            cout << "YES\n";
            for(int node : path) cout << node << " ";
            cout << endl;
            has = true;
            break;
        }
    }
    if (!has) cout << "NO\n";
    return 0;
}

