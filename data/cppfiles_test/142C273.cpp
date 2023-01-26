#include <bits/stdc++.h>
using namespace std;
bool possible(long long x, vector<vector<long long>> &p, long long n,
              long long m) {
  bool pair = 0, col[n];
  memset(col, 0, sizeof(col));
  for (long long i = 0; i < m; i++) {
    long long cnt = 0;
    for (long long j = 0; j < n; j++) {
      if (p[i][j] >= x) {
        col[j] = 1;
        cnt++;
      }
    }
    if (cnt > 1) {
      pair = 1;
    }
  }
  if (n > 1 && !pair) {
    return 0;
  }
  for (bool c : col) {
    if (!c) return 0;
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long m, n;
    cin >> m >> n;
    vector<vector<long long>> p(m, vector<long long>(n));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> p[i][j];
      }
    }
    long long ans, l = 1, r = 1e9;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (possible(mid, p, n, m)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
