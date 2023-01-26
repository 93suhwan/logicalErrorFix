#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-12;
void solve() {
  string s;
  cin >> s;
  unordered_map<char, int> mp;
  for (int i = 0; i < s.size(); ++i) {
    ++mp[s[i]];
  }
  int ans = 0;
  vector<int> v;
  for (auto [x, y] : mp) v.push_back(y);
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == 0) continue;
    bool f = false;
    while (true) {
      bool flag = false;
      for (int j = 0; j < v.size(); ++j) {
        if (i == j && v[i] >= 2 && !f) {
          v[i] -= 2;
          ++ans;
          f = true;
          flag = true;
          break;
        } else if (v[i] > 0 && v[j] > 0 && i != j) {
          --v[i];
          --v[j];
          ++ans;
          flag = true;
          break;
        }
      }
      if (!flag) break;
    }
  }
  cout << ans << '\n';
}
signed main() {
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
