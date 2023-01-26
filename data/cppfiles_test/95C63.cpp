#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<pair<int, int> > b[N];
vector<int> pmx[N], smx[N], pmn[N], smn[N];
int T, n, m;
char str[N];
bool work() {
  for (int i = 1; i <= n; ++i) {
    pmx[i].resize(m + 2);
    smx[i].resize(m + 2);
    pmn[i].resize(m + 2);
    smn[i].resize(m + 2);
    pmn[i][0] = smn[i][m + 1] = 1e9;
  }
  for (int i = m; i; --i) {
    for (int j = 1; j <= n; ++j) {
      int t = j;
      while (t < n && b[i][t].first == b[i][t + 1].first) ++t;
      for (int k = j; k <= t; ++k) {
        int p = b[i][k].second;
        smx[p][i] = max(smx[p][i + 1], b[i][t].first);
        smn[p][i] = min(smn[p][i + 1], b[i][t].first);
      }
      j = t;
    }
  }
  for (int i = 1; i < m; ++i) {
    reverse(b[i].begin() + 1, b[i].end());
    static int sL[N], sR[N];
    sL[n + 1] = 0, sR[n + 1] = 1e9;
    for (int j = 1; j <= n; ++j) {
      int t = j;
      while (t < n && b[i][t].first == b[i][t + 1].first) ++t;
      for (int k = j; k <= t; ++k) {
        int p = b[i][k].second;
        pmx[p][i] = max(pmx[p][i - 1], b[i][t].first);
        pmn[p][i] = min(pmn[p][i - 1], b[i][t].first);
      }
      j = t;
    }
    for (int j = n; j; --j) {
      sL[j] = max(sL[j + 1], pmx[b[i][j].second][i]);
      sR[j] = min(sR[j + 1], smn[b[i][j].second][i + 1]);
    }
    int pmin = 1e9, smax = 0;
    for (int t = 1; t < n; ++t) {
      pmin = min(pmin, pmn[b[i][t].second][i]);
      smax = max(smax, smx[b[i][t].second][i + 1]);
      if (pmin > sL[t + 1] && smax < sR[t + 1]) {
        cout << "YES\n";
        for (int j = 1; j <= n; ++j) str[j] = 'B';
        str[n + 1] = 0;
        for (int j = 1; j <= t; ++j) str[b[i][j].second] = 'R';
        cout << (str + 1) << ' ' << i << '\n';
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> T; T--;) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) b[i].emplace_back(0, 0);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        b[j].emplace_back(x, i);
      }
    for (int i = 1; i <= m; ++i) sort(b[i].begin() + 1, b[i].end());
    if (!work()) cout << "NO\n";
    for (int i = 1; i <= m; ++i) b[i].clear();
    for (int i = 1; i <= n; ++i) {
      pmx[i].clear(), smx[i].clear();
      pmn[i].clear(), smn[i].clear();
    }
  }
  return 0;
}
