#include <bits/stdc++.h>

using namespace std;

const int SIZE=204;
const int INF=1<<20;

bool bfs(int graph[SIZE][SIZE], int n, int s, int t, int parents[]) {
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parents[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parents[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t] == true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int graph[SIZE][SIZE];
  for(int i = 0; i < N; ++i) {
      int n;
      cin >> n;
      int s = 0, t = n - 1;
      /*
      for(int r = 0; r < n; ++r) {
          for(int c = 0; c < n; ++c) {
              graph[r][c] = 0;
          }
      }
      */
      memset(graph, 0, sizeof(graph));
      for(int j = 0; j < n - 1; ++j) {
          int m;
          cin >> m;
          int u = j;
          for(int k = 0; k < m; ++k) {
              int v;
              cin >> v;
              --v;
              if (u == 0 || v == n - 1) graph[u][v] = 1;
              else graph[u][v] = INF;
          }
      }
      int parents[n];
      int max_flow = 0;
      while (bfs(graph, n, s, t, parents)) {
          int path_flow = INT_MAX;
          for (int v = t; v != s; v = parents[v]) {
              int u = parents[v];
              path_flow = min(path_flow, graph[u][v]);
          }

          for(int v = t; v != s; v = parents[v]) {
              int u = parents[v];
              graph[u][v] -= path_flow;
              graph[v][u] += path_flow;
          }
          max_flow += path_flow;
      }
      cout << max_flow << endl;
  }
  return 0;
}

