/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    set<pair<int, int>> s, t;
    s.insert({x, x}); // end, length
    t.insert({x, x}); // length, end
    while (n--) {
        int num;
        cin >> num;
        auto it = s.lower_bound({num, 0});
        int end, len;
        tie(end, len) = *it;
        s.erase(it);
        s.insert({num, len - (end - num)});
        s.insert({end, end - num});
        t.erase({len, end});
        t.insert({len - (end - num), num});
        t.insert({end - num, end});
        cout << (*t.rbegin()).first << " ";
    }
    cout << endl;
    return 0;
}

