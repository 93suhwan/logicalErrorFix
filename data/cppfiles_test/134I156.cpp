#include <bits/stdc++.h>
using namespace std;
void prep() {}
void solve() {
  long long n, k, ans = 0;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  map<long long, long long> m;
  for (long long i = 0; i < n - 2 * k; i++) ans += a[i];
  for (long long i = n - 2 * k; i < n; i++) {
    m[a[i]]++;
  }
  long long k_ = 0;
  for (auto i : m) {
    k_ = max(k_, i.second);
  }
  if (k_ > k) ans += k_ - k;
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
