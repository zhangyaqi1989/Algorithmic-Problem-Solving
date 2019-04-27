/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

void fill_subs(vector<int> & nums, vector<int> & subs) {
    int n = nums.size();
    int limit = (1 << n) - 1;
    for(int x = 0; x <= limit; ++x) {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if ((x & (1 << i)))
                sum += nums[i];
        }
        subs.push_back(sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, A, B;
    cin >> N >> A >> B;
    int left = N / 2, right = N - left;
    vector<int> lefts, rights;
    for(int i = 0; i < left; ++i) {
        int num;
        cin >> num;
        lefts.push_back(num);
    }
    for(int i = 0; i < right; ++i) {
        int num;
        cin >> num;
        rights.push_back(num);
    }
    vector<int> subs1, subs2;
    subs1.reserve(1 << left);
    subs2.reserve(1 << right);
    fill_subs(lefts, subs1);
    fill_subs(rights, subs2);
    sort(subs1.begin(), subs1.end());
    sort(subs2.begin(), subs2.end());
    long long ans = 0;
    // for(int num1 : subs1) cout << num1 << endl;
    // cout << endl;
    // for(int num2 : subs2) cout << num2 << endl;
    for(int num1 : subs1) {
        int lo = lower_bound(subs2.begin(), subs2.end(), A - num1) - subs2.begin();
        int hi = upper_bound(subs2.begin(), subs2.end(), B - num1) - subs2.begin();
        // cout << lo << " " << hi << endl;
        ans += (hi - lo);
    }
    cout << ans << endl;
    return 0;
}

