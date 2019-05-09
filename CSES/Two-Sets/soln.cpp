/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2019
 */

#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

void printArr(vector<ll> & arr) {
    cout << arr.size() << endl;
    for(ll num : arr) cout << num << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll total = (1 + n) * n / 2;
    if (total % 2 == 1) cout << "NO\n";
    else {
        total /= 2;
        vector<ll> A, B;
        ll s = 0;
        for(ll num = n; num >= 1; --num) {
            if (s + num <= total) {
                A.push_back(num);
                s += num;
            } else {
                B.push_back(num);
            }
        }
        cout << "YES\n";
        printArr(A);
        printArr(B);
    }
    return 0;
}

