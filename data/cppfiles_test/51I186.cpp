#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 50;
int w[maxn][maxn];
int p[maxn];
int gp(int u) { return p[u] == u ? u : p[u] = gp(p[u]); }
vector<pair<int, int>> pr[100 + 1];
int n, k, d[maxn], e[maxn];
pair<int, vector<pair<int, int>>> get(vector<pair<int, int>>& cur, int u,
                                      int v) {
  for (int i = 0; i < n; i += 1) p[i] = i;
  vector<pair<int, int>> ncur;
  LL nans = 0;
  for (int i = 0; i < k; i += 1) e[i] = 0;
  for (auto [x, y] : cur) {
    if (w[u][v] < w[x][y]) {
      int pu = gp(u), pv = gp(v);
      if (pu != pv) {
        p[pu] = pv;
        ncur.push_back({u, v});
        nans += w[u][v];
        e[u] += 1;
        e[v] += 1;
      }
    }
    int px = gp(x), py = gp(y);
    if (px != py) {
      p[px] = py;
      ncur.push_back({x, y});
      nans += w[x][y];
      e[x] += 1;
      e[y] += 1;
    }
  }
  for (int i = 0; i < k; i += 1)
    if (e[i] > d[i]) return {INT_MAX, {}};
  return {nans, ncur};
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < k; i += 1) cin >> d[i];
  for (int i = 0; i < n; i += 1)
    for (int j = i + 1; j < n; j += 1) {
      cin >> w[i][j];
      w[j][i] = w[i][j];
      pr[w[i][j]].push_back({i, j});
    }
  for (int i = k; i < n; i += 1) p[i] = i;
  LL ans = 0;
  vector<pair<int, int>> cur;
  for (int i = 0; i < n - 1; i += 1) {
    cur.push_back({i, n - 1});
    ans += w[i][n - 1];
  }
  sort(cur.begin(), cur.end(),
       [&](const pair<int, int>& p, const pair<int, int>& q) {
         return w[p.first][p.second] < w[q.first][q.second];
       });
  while (true) {
    int ok = 1;
    for (int i = 0; i < n; i += 1)
      for (int j = 0; j < n; j += 1)
        if (i != j) {
          auto [nans, ncur] = get(cur, i, j);
          if (nans < ans) {
            ans = nans;
            ncur.swap(cur);
            ok = 0;
          }
        }
    if (ok) break;
  }
  cout << ans;
  return 0;
}
