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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    multiset<int> window(nums.begin(), nums.begin() + k);
    vector<int> medians;
    auto mid = next(window.begin(), k / 2);
    // cout << *mid << endl;
    int median;
    for(int i = k; ; ++i) {
        if (k % 2 == 0) {
            median = min(*mid, *prev(mid));
        } else {
            median = *mid;
        }
        medians.push_back(median);
        if (i == n) break;
        // insert nums[i]
        window.insert(nums[i]);
        if (nums[i] < *mid) --mid;
        // erase nums[i - k]
        if (nums[i - k] <= *mid) ++mid;
        window.erase(window.lower_bound(nums[i - k]));
    }
    for(auto num : medians)
        cout << num << " ";
    cout << endl;
    return 0;
}

