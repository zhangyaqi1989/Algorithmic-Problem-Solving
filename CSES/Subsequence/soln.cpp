/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * May 2019
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string dna;
    cin >> dna;
    set<char> seen;
    string ans;
    for(char ch : dna) {
        seen.insert(ch);
        if (seen.size() == 4) {
            ans += ch;
            seen.clear();
        }
    }
    string DNA = "ACGT";
    for(char ch : DNA) {
        if (seen.count(ch) == 0) {
            ans += ch;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

