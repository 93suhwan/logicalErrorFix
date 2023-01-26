#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
vector<vector<pair<int, int> > > g;
vector<int> p;
vector<int> roleM;
bool cant;
int DFS(int v, int pi) {
  p[v] = pi;
  int m = roleM[v];
  int res = (m == -1);
  for (auto& e : g[v]) {
    if (p[e.first] == pi) {
      if (roleM[e.first] != m * e.second) {
        cant = true;
        return 0;
      }
      continue;
    }
    roleM[e.first] = m * e.second;
    res += DFS(e.first, pi);
    if (cant) return 0;
  }
  return res;
}
void Solve() {
  int N, M;
  cin >> N >> M;
  g = vector<vector<pair<int, int> > >(N);
  p = vector<int>(N, -1);
  roleM = vector<int>(N);
  cant = false;
  for (int i = 0; i < M; i++) {
    int v, u;
    string s;
    cin >> v >> u >> s;
    v--;
    u--;
    int m = (s[0] == 'c' ? 1 : -1);
    g[v].emplace_back(u, m);
    g[u].emplace_back(v, m);
  }
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] == -1) {
      roleM[i] = -1;
      int r = DFS(i, i * 2);
      if (cant) break;
      roleM[i] = +1;
      r = max(r, DFS(i, i * 2 + 1));
      if (cant) break;
      res += r;
    }
  }
  if (cant)
    cout << -1 << '\n';
  else
    cout << res << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
