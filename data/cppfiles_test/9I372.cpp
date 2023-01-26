#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, long long> mp;
  long long c = 0, r = 0;
  for (char &d : s) {
    mp[d]++;
    if (mp[d] == 1) {
      c++;
      mp[d] = 0;
    }
    if (mp[d] > 1) {
      r++;
      mp[d] = 0;
    }
  }
  long long ans = c / 2 + r;
  if (ans > 0 && mp.size() == 1) {
    ans = 1;
  }
  cout << ans << '\n';
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
