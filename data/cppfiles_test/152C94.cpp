#include <bits/stdc++.h>
using namespace std;
int n;
int p[1000005];
int f[1000005][2][2];
tuple<int, int, int> pre[1000005][2][2];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 0; i <= n; i++)
    for (int k1 = 0; k1 <= 1; k1++)
      for (int k2 = 0; k2 <= 1; k2++) f[i][k1][k2] = 1e9;
  f[1][0][0] = f[1][1][0] = -1e9;
  for (int i = 1; i < n; i++) {
    for (int k1 = 0; k1 <= 1; k1++) {
      for (int k2 = 0; k2 <= 1; k2++) {
        int x, y, t = f[i][k1][k2];
        x = (2 * k1 - 1) * p[i], y = t;
        if (k2) swap(x, y);
        auto nw = make_tuple(i, k1, k2);
        for (int sgn = 0; sgn <= 1; sgn++) {
          int z = (2 * sgn - 1) * p[i + 1];
          if (z < y) continue;
          if (z < x && f[i + 1][sgn][1] > x)
            f[i + 1][sgn][1] = x, pre[i + 1][sgn][1] = nw;
          if (z >= x && f[i + 1][sgn][0] > y)
            f[i + 1][sgn][0] = y, pre[i + 1][sgn][0] = nw;
        }
      }
    }
  }
  for (int k1 = 0; k1 <= 1; k1++) {
    for (int k2 = 0; k2 <= 1; k2++) {
      if (f[n][k1][k2] != 1e9) {
        vector<int> ans;
        int i = n;
        while (i) {
          ans.push_back((2 * k1 - 1) * p[i]);
          tie(i, k1, k2) = pre[i][k1][k2];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
