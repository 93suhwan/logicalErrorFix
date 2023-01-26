#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18, mod = 1e9 + 7, maxn = 2 * 1e5 + 1;
void solve() {
  string s, t;
  cin >> t >> s;
  long long ans = 0;
  vector<long long> d(26);
  for (long long i = 0; i < 26; ++i) {
    d[t[i] - 'a'] = i;
  }
  long long n = s.size();
  for (long long i = 1; i < n; ++i) {
    ans += abs(d[s[i] - 'a'] - d[s[i - 1] - 'a']);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) {
    solve();
    cout << '\n';
  }
  return 0;
}
