#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y){};
  Point(){};
};
int sz = 350;
signed main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(0);
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
    if (a[k].x + a[k].y >= sz) {
      int j = mp[k];
      while (j < m) {
        j += a[k].x;
        if (j < m && j >= i) {
          pref[j] += d;
        } else if (j >= m) {
          break;
        }
        if (t == 2 && j < i && j + a[k].y >= i) {
          pref[i]--;
        }
        j += a[k].y;
        if (j < m && j >= i) {
          pref[j] -= d;
        }
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
          if (sm - i2 + j >= a[k].x) {
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
  for (int i = 0; i < (int)pref.size(); i++) {
    sm += pref[i];
    ans[i] += sm;
  }
  for (auto i : ans) {
    cout << i << "\n";
  }
}
