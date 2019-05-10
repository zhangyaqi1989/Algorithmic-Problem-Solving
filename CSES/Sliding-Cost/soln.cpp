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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    vector<ll> costs;
    ll median;
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);
    median = (ll) *mid;
    ll left = 0LL, right = 0LL;
    int l = k / 2 + 1, r = k - l;
    int cnt = 0;
    for(int num : window) {
        if (cnt < l) left += num;
        else right += num;
        ++cnt;
    }
    for(int i = k; ; ++i) {
        median = (ll) *mid;
        ll cost = median * l - left + right - median * r;
        costs.push_back(cost);
        if (i == n) break;
        // insert nums[i]
        window.insert(nums[i]);
        if (nums[i] < *mid) {
            --mid;
            left += nums[i];
            left -= median;
            right += median;
        } else {
            right += nums[i];
        }

        // erase nums[i - k]
        if (nums[i - k] <= *mid) {
            ++mid;
            left -= nums[i - k];
            left += *mid;
            right -= *mid;
        } else {
            right -= nums[i - k];
        }
        window.erase(window.lower_bound(nums[i - k]));
    }
    for(ll cost : costs) cout << cost << " ";
    cout << endl;
    return 0;
}

