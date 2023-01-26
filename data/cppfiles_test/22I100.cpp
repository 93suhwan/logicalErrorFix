#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point(long long x, long long y) : x(x), y(y){};
  Point(){};
};
long long sz = 0;
signed main() {
  long long n, m;
  cin >> n >> m;
  vector<Point> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  vector<long long> pref(m, 0);
  vector<vector<long long> > dp(sz + 1);
  for (long long i = 0; i < dp.size(); i++) {
    dp[i].resize(i);
  }
  vector<long long> ans(m, 0);
  map<long long, long long> mp;
  for (long long i = 0; i < m; i++) {
    long long t, k;
    cin >> t >> k;
    k--;
    long long d;
    if (t == 1) {
      mp[k] = i;
      d = 1;
    } else {
      d = -1;
    }
    if (a[k].x + a[k].y > sz) {
      long long j = mp[k];
      while (j < m) {
        j += a[k].x;
        if (j < m && j >= i) {
          pref[j] += d;
        }
        j += a[k].y;
        if (j < m && j >= i) {
          pref[j] -= d;
        }
      }
    } else {
      long long sm = (a[k].x + a[k].y);
      long long j = (mp[k] + 1) % sm;
      long long i2 = mp[k] % sm;
      while (j != i2) {
        if (j > i2) {
          if (j - i2 >= a[k].x) {
            dp[sm][j] += d;
          }
        } else {
          if (sz - i2 + j >= a[k].x) {
            dp[sm][j] += d;
          }
        }
        j = (j + 1) % sm;
      }
    }
    for (long long j = 1; j < dp.size(); j++) {
      ans[i] += dp[j][i % j];
    }
  }
  long long sm = 0;
  for (long long i = 0; i < m; i++) {
    sm += pref[i];
    ans[i] += sm;
  }
  for (auto i : ans) {
    cout << i << endl;
  }
}
