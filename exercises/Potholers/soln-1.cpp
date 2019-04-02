#include <bits/stdc++.h>

using namespace std;


bool bfs(vector<vector<int>> & graph, int s, int t, vector<int> & parents);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int INF = 1<<20;
  int N;
  cin >> N;
  for(int i = 0; i < N; ++i) {
      int n;
      cin >> n;
      vector<vector<int>> graph(n, vector<int>(n, 0));
      for(int j = 0; j < n - 1; ++j) {
          int degree;
          cin >> degree;
          int u = j;
          for(int k = 0; k < degree; ++k) {
              int v;
              cin >> v;
              --v;
              if (u == 0 || v == n - 1) graph[u][v] = 1;
              else graph[u][v] = INF;
          }

      }
      vector<int> parents(n, -1);
      int max_flow = 0;
      int s = 0, t = n - 1;
      while (bfs(graph, s, t, parents)) {
          int flow = INT_MAX;
          for(int v = t; v != s; v = parents[v]) {
              int u = parents[v];
              flow = min(flow, graph[u][v]);
          }

          for(int v = t; v != s; v = parents[v]) {
              int u = parents[v];
              graph[u][v] -= flow;
              graph[v][u] += flow;
          }
          max_flow += flow;
      }
      cout << max_flow << endl;
  }
  return 0;
}


bool bfs(vector<vector<int>> & graph, int s, int t, vector<int> & parents) {
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for(int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] > 0) {
                visited[v] = true;
                q.push(v);
                parents[v] = u;
            }
        }
    }
    return false;
}

