#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 22;
int g[N][N];
int rg[N][N];
set<pair<int, int> > e;
void solve() {
  int n, m;
  cin >> n >> m;
  auto tie = [](int u, int v) { return make_pair(min(u, v), max(u, v)); };
  for (int i = 0; i < min(N, n); i++)
    for (int j = 0; j < min(n, N); j++) {
      rg[i][j] = 1;
    }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u < N && v < N) {
      e.insert(tie(u, v));
      g[u][v] = g[v][u] = 1;
      rg[u][v] = rg[v][u] = 0;
    }
  }
  n = min(n, N);
  auto cntB = [&](int mask) {
    int res = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) res++;
    return res;
  };
  for (int mask = 0; mask < (1 << n); mask++) {
    if (cntB(mask) != 5) continue;
    vector<int> verts;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) verts.push_back(i);
    bool ok = true;
    for (int i = 0; i < int(verts.size()); i++)
      for (int j = i + 1; j < int(verts.size()); j++)
        if (!g[verts[i]][verts[j]]) {
          ok = false;
        }
    if (ok) {
      for (auto to : verts) cout << to + 1 << ' ';
      return;
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    if (cntB(mask) != 5) continue;
    vector<int> verts;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) verts.push_back(i);
    bool ok = true;
    for (int i = 0; i < int(verts.size()); i++)
      for (int j = i + 1; j < int(verts.size()); j++)
        if (!rg[verts[i]][verts[j]]) {
          ok = false;
        }
    if (ok) {
      for (auto to : verts) cout << to + 1 << ' ';
      return;
    }
  }
  cout << -1;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
