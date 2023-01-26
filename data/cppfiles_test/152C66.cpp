#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(2));
  for (int i = 1; i <= n; ++i) cin >> a[i][0], a[i][1] = -a[i][0];
  vector<vector<vector<int>>> f(
      n + 1, vector<vector<int>>(2, vector<int>(2, INT_MAX)));
  vector<vector<vector<pair<int, int>>>> prv(
      n + 1,
      vector<vector<pair<int, int>>>(2, vector<pair<int, int>>(2, {0, 0})));
  f[1][0][0] = f[1][1][0] = INT_MIN;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k)
        if (f[i][j][k] != INT_MAX) {
          for (int l = 0; l < 2; ++l) {
            if (k == 0) {
              if (a[i + 1][l] > a[i][j]) {
                if (f[i][j][k] < f[i + 1][l][0]) {
                  f[i + 1][l][0] = f[i][j][k];
                  prv[i + 1][l][0] = {j, k};
                }
              } else if (a[i + 1][l] > f[i][j][k]) {
                if (a[i][j] < f[i + 1][l][1]) {
                  f[i + 1][l][1] = a[i][j];
                  prv[i + 1][l][1] = {j, k};
                }
              }
            } else {
              if (a[i + 1][l] > f[i][j][k]) {
                if (a[i][j] < f[i + 1][l][0]) {
                  f[i + 1][l][0] = a[i][j];
                  prv[i + 1][l][0] = {j, k};
                }
              } else if (a[i + 1][l] > a[i][j]) {
                if (f[i][j][k] < f[i + 1][l][1]) {
                  f[i + 1][l][1] = f[i][j][k];
                  prv[i + 1][l][1] = {j, k};
                }
              }
            }
          }
        }
    }
  }
  for (int j = 0; j < 2; ++j) {
    for (int k = 0; k < 2; ++k) {
      if (f[n][j][k] != INT_MAX) {
        vector<int> ans(n + 1);
        for (int i = n; i > 0; --i) {
          ans[i] = a[i][j];
          pair<int, int> t = prv[i][j][k];
          j = t.first, k = t.second;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
