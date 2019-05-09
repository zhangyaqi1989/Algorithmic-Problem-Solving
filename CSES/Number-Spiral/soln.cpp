/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll r, c;
        cin >> r >> c;
        --r;
        --c;
        ll mx = max(r, c);
        ll start = (1 + 1 + 2 * (mx - 1)) * mx / 2 + 1;
        // ll end = (1 + 1 + 2 * mx) * (mx + 1) / 2;
        // cout << start << " " << end << endl;
        if (mx % 2) {
            cout << start + r + mx - c << endl;
        } else {
            cout << start + c + mx - r << endl;
        }
    }
    return 0;
}

