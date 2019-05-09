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
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    double median;
    if (n % 2 == 1) median = nums[n / 2];
    else median = 0.5 * (nums[n / 2 - 1] + nums[n / 2]);
    double ans = 0.0;
    for(int num : nums) ans += abs(num - median);
    cout << (long long) ans << endl;
    return 0;
}

