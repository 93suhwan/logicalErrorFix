#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  string s, g;
  cin >> s;
  g = s;
  long long cnt = 0;
  sort(g.begin(), g.end());
  for (long long i = 0; i < n; i++) {
    if (s[i] != g[i]) cnt++;
  }
  cout << cnt << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
