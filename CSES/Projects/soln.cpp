#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> intervals;
    for(int i = 0; i < n; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        intervals.push_back({v, u, p});
    }
    sort(intervals.begin(), intervals.end());
    vector<long long> dp(n + 1, 0LL);
    for(int i = 0; i < n; ++i) {
        int u, v, p;
        tie(v, u, p) = intervals[i];
        int idx = lower_bound(intervals.begin(), intervals.end(), make_tuple(u, 0, 0)) - intervals.begin() - 1;
        // need to compute dp[i + 1]
        // dp[i] or dp[idx + 1] + p
        dp[i + 1] = max(dp[i], dp[idx + 1] + p);
    }
    cout << dp[n] << endl;
    return 0;
}
