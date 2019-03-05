#include <bits/stdc++.h>

using namespace std;

int find(int x, int parents[]) {
    return x == parents[x] ? x : parents[x] = find(parents[x], parents);
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int n;
  int cnt = 0;
  while (true) {
      cin >> n;
      ++cnt;
      if (n == 0) break;
      int xs[n];
      int ys[n];
      int ms[n];
      double mass = 0.0;
      for(int i = 0; i < n; ++i) {
          int x, y, m;
          cin >> x >> y >> m;
          xs[i] = x;
          ys[i] = y;
          ms[i] = m;
          mass += m;
      }

      vector<tuple<double, int, int>> edges;
      for(int i = 0; i < n; ++i) {
          for(int j = i + 1; j < n; ++j) {
              int distance = (xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]);
              edges.emplace_back(distance, i, j);
          }
      }
      sort(edges.begin(), edges.end());
      int parents[n];
      for(int i = 0; i < n; ++i) parents[i] = i;
      vector<tuple<double, int, int>> cands;
      for(auto & edge : edges) {
          int x = get<1>(edge), y = get<2>(edge);
          int rx = find(x, parents), ry = find(y, parents);
          if (rx != ry) {
              parents[rx] = parents[ry];
              double distance = sqrt(get<0>(edge));
              cands.push_back(make_tuple(distance, x, y));
          }
      }
      // cout << cands.size() << endl;
      sort(cands.begin(), cands.end());
      set<int> not_connects;
      for(int i = 0; i < n; ++i){
          parents[i] = i;
          not_connects.insert(i);
      }
      not_connects.erase(0);
      double ans = 0.0;
      for(auto & edge : cands) {
          int x = get<1>(edge), y = get<2>(edge);
          double distance = get<0>(edge);
          // cout << distance << endl;
          int rx = find(x, parents), ry = find(y, parents);
          if (rx != ry) parents[rx] = parents[ry];
          set<int> remove;
          for(auto island : not_connects) {
              if (find(island, parents) == find(0, parents)) {
                  remove.insert(island);
                  ans += distance * ms[island];
              }
          }
          for(auto idx : remove) not_connects.erase(idx);
      }
// Island Group: 1 Average 3.20
       printf("Island Group: %d Average %0.2lf\n", cnt, ans/mass);
      // cout << std::setprecision(2) << ans / mass << endl;
  }
  return 0;
}

