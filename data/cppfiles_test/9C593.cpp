#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-12;
void solve() {
  string s;
  cin >> s;
  unordered_map<int, int> mp;
  for (auto ch : s) ++mp[ch];
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (mp[s[i]] >= 2) {
      ans += 2;
      mp[s[i]] = 0;
    } else if (mp[s[i]]) {
      ++ans;
    }
  }
  cout << ans / 2 << '\n';
}
signed main() {
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
