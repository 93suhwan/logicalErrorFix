#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i += k) {
    if (a[i] > 0) break;
    ans += 2 * abs(a[i]);
  }
  for (int i = n - 1; i >= 0; i -= k) {
    if (a[i] < 0) break;
    ans += 2 * abs(a[i]);
  }
  cout << ans - max(abs(a[0]), abs(a[n - 1])) << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
