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
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    unordered_set<int> seen;
    int node = 0, k = 0;
    queue<pair<int, int>> frontier;
    frontier.push({0, 0});
    seen.insert(0);
    while (!frontier.empty()) {
        tie(node, k) = frontier.front();
        frontier.pop();
        for(int nei : tree[node]) {
            if (seen.count(nei) == 0) {
                seen.insert(nei);
                frontier.push({nei, k + 1});
            }
        }
    }
    frontier.push({node, 0});
    seen.clear();
    seen.insert(node);
    while (!frontier.empty()) {
        tie(node, k) = frontier.front();
        frontier.pop();
        for(int nei : tree[node]) {
            if (seen.count(nei) == 0) {
                seen.insert(nei);
                frontier.push({nei, k + 1});
            }
        }
    }
    cout << k << endl;
    return 0;
}

