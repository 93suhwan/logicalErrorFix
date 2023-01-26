#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i];
      if (i % 2 == 0) a[i] *= -1;
    }
    vector<long long> pref(n + 1);
    for (long long i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    long long ans = 0;
    for (long long l = 1; l <= n; l += 2) {
      long long cur = 0;
      long long mn = a[l] - 1;
      for (long long r = l + 1; r <= n; r += 2) {
        cur += a[r - 1];
        if (cur + a[r] >= 0) {
          long long tt = cur + a[r];
          if (tt <= mn) {
            ans++;
            long long rem = mn - tt;
            ans += min(abs(a[r] + 1), rem);
          }
        } else {
          if (cur > 0) {
            long long tmp = -cur;
            long long tt = cur + tmp;
            if (tt <= mn) {
              ans++;
              long long rem = mn - tt;
              ans += min(abs(tmp + 1), rem);
            }
          }
        }
        cur += a[r];
        mn = min(mn, cur);
        if (mn < 0) break;
        ;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
