#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<int>>& v1, vector<vector<int>>& v2, string t) {
  int cur = -1;
  bool ok = 1;
  for (int i = 0; i < (int)t.size(); i++) {
    int q = t[i] - 'a';
    if (i % 2 == 0) {
      int pos = upper_bound(v1[q].begin(), v1[q].end(), cur) - v1[q].begin();
      if (pos == (int)v1[q].size()) {
        ok = 0;
        break;
      }
      cur = v1[q][pos];
    } else {
      int pos = upper_bound(v2[q].begin(), v2[q].end(), cur) - v2[q].begin();
      if (pos == (int)v2[q].size()) {
        ok = 0;
        break;
      }
      cur = v2[q][pos];
    }
  }
  return ok;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> odd(26);
    vector<vector<int>> even(26);
    for (int i = 0; i < (int)s.size(); i++) {
      if (i % 2 == 0) {
        even[(int)(s[i] - 'a')].push_back(i);
      } else {
        odd[(int)(s[i] - 'a')].push_back(i);
      }
    }
    if (solve(odd, even, t) or solve(even, odd, t))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
