#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int Lmin[n + 1][m + 1], Lmax[n + 1][m + 1], Rmin[n + 1][m + 1],
      Rmax[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    Lmin[i][1] = Lmax[i][1] = a[i][1];
    Rmin[i][m] = Rmax[i][m] = a[i][m];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++) {
      Lmax[i][j] = max(Lmax[i][j - 1], a[i][j]);
      Lmin[i][j] = min(Lmin[i][j - 1], a[i][j]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = m - 1; j >= 1; j--) {
      Rmax[i][j] = max(Rmax[i][j + 1], a[i][j]);
      Rmin[i][j] = min(Rmin[i][j + 1], a[i][j]);
    }
  for (int j = 1; j < m; j++) {
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) v.push_back(make_pair(Lmin[i][j], i));
    sort(v.begin(), v.end());
    int num[n + 1];
    for (int i = 1; i <= n; i++) num[i] = v[i - 1].second;
    int Lmaxv[n + 2], Lminv[n + 2], Rmaxv[n + 2], Rminv[n + 2];
    for (int i = 0; i <= n + 1; i++)
      Lmaxv[i] = Rmaxv[i] = 0, Lminv[i] = Rminv[i] = 1e9;
    for (int i = 1; i <= n; i++) {
      Lmaxv[i] = max(Lmaxv[i - 1], Lmax[num[i]][j]);
      Rminv[i] = min(Rminv[i - 1], Rmin[num[i]][j + 1]);
    }
    for (int i = n; i >= 1; i--) {
      Lminv[i] = min(Lminv[i + 1], Lmin[num[i]][j]);
      Rmaxv[i] = max(Rmaxv[i + 1], Rmax[num[i]][j + 1]);
    }
    for (int i = 1; i < n; i++) {
      if (Lmaxv[i] < Lminv[i + 1] && Rminv[i] > Rmaxv[i + 1]) {
        cout << "YES\n";
        char s[n + 1];
        s[n] = 0;
        for (int k = 1; k <= n; k++) s[num[k] - 1] = (k <= i ? 'B' : 'R');
        cout << s << " " << j << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
