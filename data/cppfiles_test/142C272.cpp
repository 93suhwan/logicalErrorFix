#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool check(long long x, vector<vector<long long>> p) {
  long long ctr;
  bool a[n];
  for (long long i = 0; i < n; i++) a[i] = false;
  bool yn = false, ans = true;
  for (long long i = 0; i < m; i++) {
    ctr = 0;
    for (long long j = 0; j < n; j++) {
      if (p[i][j] >= x) {
        ctr++;
        a[j] = true;
      }
    }
    if (ctr > 1) yn = true;
  }
  if (!yn) return false;
  for (bool i : a) ans = ans & i;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    vector<vector<long long>> p(m, vector<long long>(n));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) cin >> p[i][j];
    }
    long long hi = 1e9, lo = 0, ans = 0, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (check(mid, p)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
