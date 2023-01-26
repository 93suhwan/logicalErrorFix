#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y){};
  Point(){};
};
int sz = 300;
signed main() {
  int n, m;
  cin >> n >> m;
  vector<Point> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  vector<int> pref(m, 0);
  vector<vector<int> > dp(sz + 1);
  for (int i = 0; i < dp.size(); i++) {
    dp[i].resize(i);
  }
  vector<int> ans(m, 0);
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    int t, k;
    cin >> t >> k;
    k--;
    int d;
    if (t == 1) {
      mp[k] = i;
      d = 1;
    } else {
      d = -1;
    }
    if (a[k].x + a[k].y > sz) {
      int j = i + a[k].x;
      while (j < m) {
        pref[j] += d;
        if (j + a[k].y < m) {
          pref[j + a[k].y] -= d;
        }
        j += a[k].y;
        j += a[k].x;
      }
    } else {
      int sm = (a[k].x + a[k].y);
      int j = (mp[k] + 1) % sm;
      int i2 = mp[k] % sm;
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
    for (int j = 1; j < dp.size(); j++) {
      ans[i] += dp[j][i % j];
    }
  }
  int sm = 0;
  for (int i = 0; i < m; i++) {
    sm += pref[i];
    ans[i] += sm;
  }
  for (auto i : ans) {
    cout << i << endl;
  }
}
