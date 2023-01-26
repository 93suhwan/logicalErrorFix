#include <bits/stdc++.h>
using namespace std;
vector<int> a[500005], minst[500005], mindr[500005], maxst[500005],
    maxdr[500005];
struct elem {
  int x, index;
};
inline bool cmp(const elem &a, const elem &b) {
  if (a.x == b.x) return a.index < b.index;
  return a.x < b.x;
}
elem v[2000002], w[2000002];
int fv[1000002], fw[1000002];
int main() {
  int t, l, n, m, i, j, k, xv, xw, dif, ok;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (l = 1; l <= t; l++) {
    cin >> n >> m;
    for (i = 1; i <= n; i++)
      for (j = 0; j <= m + 1; j++)
        a[i].push_back(0), minst[i].push_back(0), mindr[i].push_back(0),
            maxst[i].push_back(0), maxdr[i].push_back(0);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) cin >> a[i][j];
      minst[i][1] = a[i][1];
      maxst[i][1] = a[i][1];
      for (j = 2; j <= m; j++) {
        minst[i][j] = min(a[i][j], minst[i][j - 1]);
        maxst[i][j] = max(a[i][j], maxst[i][j - 1]);
      }
      mindr[i][m] = a[i][m];
      maxdr[i][m] = a[i][m];
      for (j = m - 1; j >= 1; j--) {
        mindr[i][j] = min(a[i][j], mindr[i][j + 1]);
        maxdr[i][j] = max(a[i][j], maxdr[i][j + 1]);
      }
    }
    ok = 0;
    for (k = 1; k < m && ok == 0; k++) {
      for (i = 1; i <= n; i++) {
        v[i * 2 - 1] = {minst[i][k], i}, v[i * 2] = {maxst[i][k], i};
        w[i * 2 - 1] = {mindr[i][k + 1], i}, w[i * 2] = {maxdr[i][k + 1], i};
      }
      sort(v + 1, v + 2 * n + 1, cmp);
      sort(w + 1, w + 2 * n + 1, cmp);
      xv = 0;
      xw = 0;
      dif = 0;
      for (i = 1, j = 2 * n; i < 2 * n && ok == 0; i++, j--) {
        fv[v[i].index]++;
        if (fv[v[i].index] == 2)
          xv--;
        else
          xv++;
        if (fv[v[i].index] == 2) {
          if (fw[v[i].index] != 2) dif++;
          if (fw[v[i].index] == 2) dif--;
        }
        fw[w[j].index]++;
        if (fw[w[j].index] == 2)
          xw--;
        else
          xw++;
        if (fw[w[j].index] == 2) {
          if (fv[w[j].index] != 2) dif++;
          if (fv[w[j].index] == 2) dif--;
        }
        if (dif == 0 && xv == 0 && xw == 0 && v[i].x != v[i + 1].x &&
            w[j].x != w[j - 1].x) {
          ok = 1;
          break;
        }
      }
      if (ok == 1) {
        break;
      }
      for (i = 1; i <= n; i++) fv[i] = 0;
      for (i = 1; i <= n; i++) fw[i] = 0;
    }
    if (ok == 1) {
      cout << "YES" << '\n';
      for (i = 1; i <= n; i++)
        if (fv[i] == 2)
          cout << 'B';
        else
          cout << 'R';
      cout << " " << k << '\n';
    } else
      cout << "NO" << '\n';
    for (i = 1; i <= n; i++)
      a[i].clear(), minst[i].clear(), mindr[i].clear(), maxst[i].clear(),
          maxdr[i].clear(), fv[i] = fw[i] = 0;
  }
  return 0;
}
