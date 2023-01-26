#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000001;
const long long LLINF = 9223372036854775807;
const long long M = 998244353;
const double EPS = 1e-6;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long> > a(n);
    long long s1 = 0, s2 = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      s1 += a[i].first;
      s2 += a[i].second;
    }
    bool swpd = false;
    if (s1 < s2) {
      swpd = true;
      for (long long i = 0; i < n; i++) {
        swap(a[i].first, a[i].second);
      }
    }
    long long a0 = 0, b0 = 0;
    vector<pair<long long, long long> > ans(n);
    for (long long i = 0; i < n; i++) {
      if (a[i].first >= m) {
        a0 += a[i].first - m;
        b0 += a[i].second;
        ans[i].first = m;
        ans[i].second = 0;
      } else {
        b0 += a[i].second - (m - a[i].first);
        ans[i].first = a[i].first;
        ans[i].second = m - a[i].first;
      }
    }
    if (a0 >= b0) {
      cout << abs(a0 - b0) << "\n";
      for (long long i = 0; i < n; i++) {
        if (swpd) swap(ans[i].first, ans[i].second);
        cout << ans[i].first << ' ' << ans[i].second << "\n";
      }
    } else {
      long long d;
      for (long long i = 0; i < n; i++) {
        d = min({abs(a0 - b0) / 2, ans[i].first, a[i].second - ans[i].second});
        a0 += d;
        b0 -= d;
        ans[i].first -= d;
        ans[i].second += d;
      }
      cout << abs(a0 - b0) << "\n";
      for (long long i = 0; i < n; i++) {
        if (swpd) swap(ans[i].first, ans[i].second);
        cout << ans[i].first << ' ' << ans[i].second << "\n";
      }
    }
  }
  return 0;
}
