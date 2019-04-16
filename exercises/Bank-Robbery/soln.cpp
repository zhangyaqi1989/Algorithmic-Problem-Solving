#include <bits/stdc++.h>

const int INF = 1 << 20;

using namespace std;

bool bfs(vector<int> graph[], map<pair<int, int>, int> & capacity, int N, int s, int t, int parents[]) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parents[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for(int v : graph[u]) {
            if (!visited[v] && capacity[{u, v}] > 0) {
                q.push(v);
                parents[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    vector<int> temp[n] = {{}};
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        temp[a].push_back(b);
        temp[b].push_back(a);
    }
    vector<int> graph[2 * n] = {{}};
    map<pair<int, int>, int> capacity;
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            for(int nei : temp[i]) {
                graph[s].push_back(nei);
                capacity[{s, nei}] = 1;
                graph[nei].push_back(s);
                capacity[{nei, s}] = 0;
            }
        } else if (i == t) {
            for(int nei : temp[i]) {
                graph[t].push_back(nei + n);
                capacity[{t, nei + n}] = 0;
                graph[nei+n].push_back(t);
                capacity[{nei+n, t}] = 1;
            }
        } else {
            for(int nei : temp[i]) {
                if (nei != s && nei != t) {
                    graph[i + n].push_back(nei);
                    graph[nei].push_back(i + n);
                    capacity[{nei, i + n}] = 0;
                    capacity[{i + n, nei}] = INF;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if (i != t && i != s) {
            graph[i].push_back(i + n);
            capacity[{i, i + n}] = 1;
            graph[i + n].push_back(i);
            capacity[{i + n, i}] = 0;
        }
    }

    int parents[2 * n] = {0};
    int max_flow = 0;
    while (bfs(graph, capacity, 2 * n, s, t, parents)) {
        int path_flow = INT_MAX;
        for(int v = t; v != s; v = parents[v]) {
            int u = parents[v];
            path_flow = min(path_flow, capacity[{u, v}]);
        }
        for(int v = t; v != s; v = parents[v]) {
            int u = parents[v];
            capacity[{u, v}] -= path_flow;
            capacity[{v, u}] += path_flow;
        }
        // assert(path_flow != 0);
        max_flow += path_flow;
    }
    cout << max_flow << endl;
    return 0;
}
