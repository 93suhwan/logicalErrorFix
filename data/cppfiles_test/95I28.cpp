#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    vector<vector<long long>> pmn(n, vector<long long>(m)),
        pmx(n, vector<long long>(m));
    vector<vector<long long>> smn(n, vector<long long>(m)),
        smx(n, vector<long long>(m));
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
      pmn[i][0] = a[i][0];
      for (long long j = 1; j < m; ++j) {
        pmn[i][j] = min(pmn[i][j - 1], a[i][j]);
      }
      pmx[i][0] = a[i][0];
      for (long long j = 1; j < m; ++j) {
        pmx[i][j] = max(pmx[i][j - 1], a[i][j]);
      }
      smx[i][m - 1] = a[i][m - 1];
      for (long long j = m - 2; j >= 0; --j) {
        smx[i][j] = max(smx[i][j + 1], a[i][j]);
      }
      smn[i][m - 1] = a[i][m - 1];
      for (long long j = m - 2; j >= 0; --j) {
        smn[i][j] = min(smn[i][j + 1], a[i][j]);
      }
    }
    long long res_k = -1;
    bool good = false;
    for (long long k = 0; k < m - 1; ++k) {
      set<pair<long long, long long>> red, blue, red1, blue1;
      for (long long i = 0; i < n; ++i) {
        red.insert({pmn[i][k], i});
        red1.insert({smx[i][k + 1], i});
        blue.insert({pmx[i][k], i});
      }
      vector<bool> res(n);
      for (auto [x, i] : blue) {
        red.erase({pmn[i][k], i});
        red1.erase({smx[i][k + 1], i});
        blue1.insert({smn[i][k + 1], i});
        res[i] = 1;
        if (red.begin()->first > x) {
          if (blue1.begin()->first > red1.rend()->first) {
            good = true;
            break;
          }
        }
      }
      if (good) {
        cout << "YES\n";
        for (bool x : res) {
          if (x) {
            cout << 'B';
          } else {
            cout << 'R';
          }
        }
        cout << ' ' << k + 1 << '\n';
        break;
      }
    }
    if (!good) {
      cout << "NO\n";
    }
  }
}
