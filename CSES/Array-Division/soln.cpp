/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

bool valid(vector<int> & nums, int k, ll m) {
    int cnt = 1;
    ll acc = 0LL;
    for(int num : nums) {
        if (num > m) return false;
        if (acc + num <= m) {
            acc += num;
        } else {
            if (++cnt > k) return false;
            acc = num;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    ll hi = 0LL;
    for(int num : nums) hi += num;
    ll lo = 0LL;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (valid(nums, k, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
        // cout << lo << " " << mid << " " << hi << endl;
    }
    cout << lo << endl;
    return 0;
}
