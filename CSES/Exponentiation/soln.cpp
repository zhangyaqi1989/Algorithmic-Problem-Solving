/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * April 2019
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;


int mypow(ll a, ll b, int mod) {
    ll r = 1, e = a;
    while (b) {
        if (b & 1) r = (r * e) % mod;
        e = (e * e) % mod;
        b >>= 1;
    }
    return r;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << mypow(a, b, mod) << endl;
    }
    return 0;
}

