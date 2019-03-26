#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d; // number of data set
  cin >> d;
  int dp[50][50];
  bool idxes[50];
  for(int p = 0; p < d; ++p) {
      int n, k, idx;
      cin >> n >> k;
      for(int i = 0; i < 50; ++i) idxes[i] = false;
      for(int q = 0; q < k; ++q) {
          cin >> idx;
          idxes[idx] = true;
      }
      memset(dp, 0, sizeof(dp));
      dp[1][1] = 1;
      for(int i = 2; i <= 2 * n; ++i) {
          for(int j = 0; j <= 2 * n; ++j) {
              if (!idxes[i]) {
                  if (j == 0) dp[i][0] = dp[i - 1][1];
                  else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
              } else {
                  if (j == 0) dp[i][0] = 0;
                  else dp[i][j] = dp[i - 1][j - 1];
              }
          }
      }
      cout << dp[2 * n][0] << endl;
  }
  return 0;
}

