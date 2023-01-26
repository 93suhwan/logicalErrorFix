#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, a[N];
void init() {}
void solve() {
  cin >> n;
  long long res = -1e10;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) res = max(a[i] - a[i - 1], res);
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
