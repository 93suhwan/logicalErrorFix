#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
void init_code() {}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s1 = s;
  sort(s1.begin(), s1.end());
  int ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != s1[i]) ans++;
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
