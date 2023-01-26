#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  unordered_map<char, int> mp;
  for (auto x : s) {
    mp[x]++;
  }
  int res1 = 0, res2 = 0;
  for (auto x : mp) {
    if (x.second > 1) {
      res2++;
    } else
      res1++;
  }
  cout << res2 + res1 / 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int te;
  cin >> te;
  while (te--) solve();
  return 0;
}
