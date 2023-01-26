#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using vi = vector<int64_t>;
using pii = pair<int64_t, int64_t>;
ll powr(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
void solve() {
  int64_t n, k;
  cin >> n >> k;
  k++;
  int64_t a[n];
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = powr(10, a[i]);
  }
  sort(a, a + n);
  int64_t ans = 0;
  for (int64_t i = 0; i < n - 1 && k > 0; i++) {
    int64_t den = min(k, (a[i + 1] / a[i]) - 1);
    ans += a[i] * den;
    k -= den;
  }
  if (k > 0) {
    ans += a[n - 1] * k;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t t;
  cin >> t;
  while (t--) solve();
}
