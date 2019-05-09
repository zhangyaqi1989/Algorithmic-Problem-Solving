/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * April 2019
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> hs(n + 2);
    hs[0] = -1;
    for(int i = 0; i < n; ++i) cin >> hs[i + 1];
    hs[n + 1] = -1;
    stack<int> stk;
    long long mx_area = 0LL;
    for(int i = 0; i < n + 2; ++i) {
        while (!stk.empty() && hs[i] < hs[stk.top()]) {
            int h = hs[stk.top()];
            stk.pop();
            int w = i - stk.top() - 1;
            mx_area = max(mx_area, (long long) h * w);
        }
        stk.push(i);
    }
    cout << mx_area << endl;
    return 0;
}

