#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, long long> mp;
  long long c = 0, r = 0;
  for (char &d : s) {
    mp[d]++;
    if (mp[d] > 1) {
      mp[d] = 2;
    }
  }
  long long su = 0;
  for (auto &x : mp) {
    su += (x.second);
  }
  cout << su / 2 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
