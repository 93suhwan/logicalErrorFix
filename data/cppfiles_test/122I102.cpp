#include <bits/stdc++.h>
using namespace std;
struct Q {
  int v, w;
  Q() {}
  Q(int a, int b) : v(a), w(b) {}
};
const int N = 2e5 + 2;
vector<Q> e[N];
int pc[N], col[N], eg[N][2];
bool flg;
void dfs1(int u) {
  for (auto [v, w] : e[u])
    if (col[v] != -1) {
      if ((col[u] ^ w) != col[v]) {
        flg = 1;
        return;
      }
    } else
      col[v] = w ^ col[u], dfs1(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i < N; i++) pc[i] = pc[i >> 1] ^ (i & 1);
  while (T--) {
    int n, m, i;
    cin >> n >> m;
    flg = 0;
    for (i = 1; i <= n; i++) e[i].clear(), col[i] = -1;
    for (i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      eg[i][0] = u;
      eg[i][1] = v;
      eg[i][2] = w;
      if (w >= 0) {
        e[u].emplace_back(v, pc[w]);
        e[v].emplace_back(u, pc[w]);
      }
    }
    while (m--) {
      int u, v, p;
      cin >> u >> v >> p;
      e[u].emplace_back(v, p);
      e[v].emplace_back(u, p);
    }
    for (i = 1; i <= n; i++)
      if (col[i] == -1) col[i] = 0, dfs1(i);
    if (flg) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (i = 1; i < n; i++)
      if (eg[i][2] >= 0)
        cout << eg[i][0] << ' ' << eg[i][1] << ' ' << eg[i][2] << '\n';
      else
        cout << eg[i][0] << ' ' << eg[i][1] << ' '
             << (col[eg[i][0]] != col[eg[i][1]]) << '\n';
  }
}
