#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector<int> cnta(n + 1), cntb(n + 1);
  for (int i = 0; i < n; ++i) {
    ++cnta[a[i]];
    ++cntb[b[i]];
  }
  int64_t ans = int64_t(n) * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; ++i) ans -= int64_t(cnta[a[i]] - 1) * (cntb[b[i]] - 1);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
