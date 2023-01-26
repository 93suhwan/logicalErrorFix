#include <bits/stdc++.h>
using namespace std;
void fast(void) __attribute__((constructor));
void fast(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long m;
  cin >> m;
  vector<long long> a(m), b(m);
  for (long long i = 0; i < m; ++i) cin >> a[i];
  for (long long i = 0; i < m; ++i) cin >> b[i];
  vector<long long> pref(m + 1);
  for (long long i = 0; i < m; ++i) {
    pref[i + 1] = pref[i] + b[i];
  }
  vector<long long> suf(m + 1);
  for (long long i = m - 1; i >= 0; --i) {
    suf[i] = suf[i + 1] + a[i];
  }
  long long ans = (long long)1e9;
  for (long long i = 0; i < m; ++i) {
    ans = min(ans, max(pref[i], suf[i + 1]));
  }
  cout << ans;
}
signed main(void) {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
