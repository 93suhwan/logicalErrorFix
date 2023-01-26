#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const int N = 2 * 1e5 + 5;
const long double eps = 1e-9;
const int mod = 1e9 + 7;
vector<pair<pair<int, int>, int>> restriciones;
vector<int> tree[N];
vector<pair<int, int>> g[N];
int rs[N];
map<pair<int, int>, int> arcos;
bool flayo = false;
void clean(int n) {
  restriciones.clear();
  arcos.clear();
  for (int i = 0; i <= n + 1; ++i) {
    tree[i].clear();
    g[i].clear();
    rs[i] = -1;
  }
}
void dfs2(int v, int c) {
  rs[v] = c;
  for (auto &x : g[v]) {
    int cc = c ^ x.second;
    if (rs[x.first] == -1) {
      dfs2(x.first, cc);
      if (flayo) return;
    } else if (rs[x.first] != cc) {
      flayo = true;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T, x, y, n, m, v, p, a, b, c;
  cin >> T;
  memset(rs, -1, sizeof rs);
  while (T--) {
    cin >> n >> m;
    flayo = false;
    for (int i = 1; i < n; ++i) {
      cin >> x >> y >> v;
      if (x > y) swap(x, y);
      tree[x].push_back(y);
      tree[y].push_back(x);
      arcos[{x, y}] = v;
      if (v >= 0) {
        restriciones.push_back({{x, y}, v & 1});
      }
    }
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> p;
      restriciones.push_back({{a, b}, p});
    }
    for (auto &r : restriciones) {
      a = r.first.first, b = r.first.second, c = r.second;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }
    for (int i = 1; i <= n && !flayo; ++i) {
      if (rs[i] == -1) {
        dfs2(i, 0);
      }
    }
    if (flayo) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto &arc : arcos) {
        if (arc.second == -1) {
          arc.second = rs[arc.first.first] ^ rs[arc.first.second];
        }
        cout << arc.first.first << " " << arc.first.second << " " << arc.second
             << "\n";
      }
    }
    clean(n);
  }
}
