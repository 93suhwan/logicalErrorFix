#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long a[N], b[N], ta[N], tb[N], n, tta[N], ttb[N];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (long long i = n; i >= 1; i--) {
    tta[b[i]] += ta[a[i]];
    ttb[a[i]] += tb[b[i]];
    ta[a[i]]++;
    tb[b[i]]++;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ta[a[i]]--;
    tb[b[i]]--;
    tta[b[i]] -= ta[a[i]];
    ttb[a[i]] -= tb[b[i]];
    ans += ta[a[i]] * tb[b[i]] + tta[b[i]] + ttb[a[i]];
  }
  cout << n * (n - 1) / 2 * (n - 2) / 3 - ans << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
