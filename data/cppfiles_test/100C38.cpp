#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if (a[n - 2] == a[n - 1]) {
    long long r = 1;
    for (int i = 1; i <= n; i++) r *= i, r %= MOD;
    cout << r << "\n";
    return;
  }
  if (a[n - 1] - a[n - 2] > 1) {
    cout << "0\n";
    return;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == a[n - 2]) cnt++;
  long long ans = 1;
  for (int i = 1; i <= n; i++)
    if (i != cnt + 1) ans *= i, ans %= MOD;
  ans *= cnt;
  ans %= MOD;
  cout << ans << "\n";
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
