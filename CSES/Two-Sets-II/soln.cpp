/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const int INF = 0x3f3f3f3f;

ll memo[501][126000];
int n;
const int mod = 1e9 + 7;

ll helper(int num, int acc, int target) {
    if (memo[num][acc] != -1) return memo[num][acc];
    if (num == n) return acc == target;
    ll ans = helper(num + 1, acc, target) % mod;
    if (num + acc <= target) ans = (ans + helper(num + 1, acc + num, target)) % mod;
    memo[num][acc] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int total = (1 + n) * n / 2;
    if (total % 2 == 1) cout << 0 << endl;
    else {
        int target = total / 2;
        memset(memo, -1, sizeof(memo));
        cout << helper(1, 0, target) << endl;
    }
    return 0;
}

