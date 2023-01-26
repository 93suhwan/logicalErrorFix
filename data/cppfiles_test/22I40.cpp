#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point(long long x, long long y) : x(x), y(y){};
  Point(){};
};
long long sz = 3000000000000;
signed main() {
  long long n, m;
  cin >> n >> m;
  vector<Point> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  vector<long long> pref(m, 0);
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
      mp.erase(k);
      d = -1;
    }
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
  }
  long long sm = 0;
  for (long long i = 0; i < (long long)pref.size(); i++) {
    sm += pref[i];
    ans[i] += sm;
  }
  for (auto i : ans) {
    cout << i << endl;
  }
}
