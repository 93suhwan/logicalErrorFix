#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
long long a[MAXN], sum[MAXN];
void solve() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i], sum[i + 1] = sum[i] + a[i];
  sort(a, a + n);
  cin >> m;
  long long x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    int p = lower_bound(a, a + n, x) - a;
    long long ans = 0;
    if (p == n)
      ans = x - a[n - 1] + max(0ll, y - sum[n] + a[n - 1]);
    else
      ans = max(0ll, y - sum[n] + a[p]);
    if (p > 0 && p < n)
      ans = min(ans, x - a[p - 1] + max(0ll, y - sum[n] + a[p - 1]));
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
