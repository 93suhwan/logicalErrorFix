#include <bits/stdc++.h>
using namespace std;
long long n, v[200005], sum[200005], k;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long ans = LLONG_MAX;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> v[i];
      sum[i] = 0;
    }
    if (n == 1) {
      cout << max(v[1] - k, 0LL);
      cout << '\n';
      continue;
    }
    sort(v + 1, v + n + 1);
    for (long long i = 2; i <= n; i++) sum[i] = sum[i - 1] + v[i];
    long long st = -1e18, dr = v[1];
    while (st <= dr) {
      long long nr = ans;
      long long nr_pasi = 1, ok = 1;
      long long mijl = (st + dr) / 2;
      if (mijl + sum[n] <= k) {
        ok = 0;
        if (v[1] - mijl <= ans) ans = v[1] - mijl;
      }
      for (long long i = n; i >= 2 && ok == 1; i--) {
        if (sum[i - 1] + mijl + (n - i + 1) * mijl <= k) {
          ok = 0;
          ans = min(ans, v[1] - mijl + n - i + 1);
        }
      }
      if (ok == 0 && ans != nr)
        st = mijl + 1;
      else
        dr = mijl - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
