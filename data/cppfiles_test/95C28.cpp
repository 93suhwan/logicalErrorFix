#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1.0);
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  int lmin[n + 1][m + 1], lmax[n + 1][m + 1];
  int rmin[n + 1][m + 1], rmax[n + 1][m + 1];
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) cin >> a[i][j];
  for (int i = (1); i <= (n); i++) {
    lmin[i][1] = lmax[i][1] = a[i][1];
    rmin[i][m] = rmax[i][m] = a[i][m];
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (2); j <= (m); j++) {
      lmin[i][j] = min(lmin[i][j - 1], a[i][j]);
      lmax[i][j] = max(lmax[i][j - 1], a[i][j]);
    }
    for (int j = (m - 1); j >= (1); j--) {
      rmin[i][j] = min(rmin[i][j + 1], a[i][j]);
      rmax[i][j] = max(rmax[i][j + 1], a[i][j]);
    }
  }
  for (int j = 1; j < m; j++) {
    pair<int, int> g[n + 1];
    for (int i = (1); i <= (n); i++) g[i] = {lmin[i][j], i};
    sort(g + 1, g + n + 1);
    int lmaxv[n + 1], lminv[n + 1], rmaxv[n + 1], rminv[n + 1];
    lmaxv[1] = lmax[g[1].second][j];
    rminv[1] = rmin[g[1].second][j + 1];
    lminv[n] = lmin[g[n].second][j];
    rmaxv[n] = rmax[g[n].second][j + 1];
    for (int i = 2; i <= n; i++) {
      lmaxv[i] = max(lmaxv[i - 1], lmax[g[i].second][j]);
      rminv[i] = min(rminv[i - 1], rmin[g[i].second][j + 1]);
    }
    for (int i = n - 1; i >= 1; i--) {
      lminv[i] = min(lminv[i + 1], lmin[g[i].second][j]);
      rmaxv[i] = max(rmaxv[i + 1], rmax[g[i].second][j + 1]);
    }
    for (int i = 1; i < n; i++) {
      if (lmaxv[i] < lminv[i + 1] && rminv[i] > rmaxv[i + 1]) {
        cout << "YES\n";
        string ans(n + 1, 'R');
        for (int j = 1; j <= i; j++) {
          ans[g[j].second] = 'B';
        }
        cout << ans.substr(1) << " " << j << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
