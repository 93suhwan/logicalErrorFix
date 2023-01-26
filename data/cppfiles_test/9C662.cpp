#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, long long> m;
  for (auto x : s) {
    m[x]++;
  }
  long long ans = 0, cnt = 0;
  for (auto x : m) {
    if (x.second == 1)
      cnt++;
    else
      ans++;
  }
  ans += cnt / 2;
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
