/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * May 2019
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> times;
    for(int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        times.push_back({s, e, i});
    }
    int mx = 0;
    multiset<pair<int, int>> ends;
    vector<int> ids(n);
    sort(times.begin(), times.end());
    // const int INF = 0x3f3f3f3f;
    for(auto & time : times){
        int s, e, i;
        tie(s, e, i) = time;
        // all times in it is larger than s
        if (ends.empty() || (*ends.begin()).first >= s) {
            ++mx;
            ids[i] = mx;
            ends.insert({e, mx});
        } else {
            ids[i] = (*ends.begin()).second;
            ends.erase(ends.begin());
            ends.insert({e, ids[i]});
        }

    }
    cout << mx << endl;
    for(int i = 0; i < n; ++i) cout << ids[i] << " ";
    cout << endl;
    return 0;
}

