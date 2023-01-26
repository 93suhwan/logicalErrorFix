#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
ll mod = 1e9 + 7;
int const N = 3e5 + 100;
mt19937 rnd;
ll random(ll limit) {
  uniform_int_distribution<ll> uniform_dist(0, limit);
  return uniform_dist(rnd);
}
ll bpow(ll a, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p % 2) {
      res = res * a % mod;
    }
    a = a * a % mod;
    p /= 2;
  }
  return res;
}
ll inv(ll a) { return bpow(a, mod - 2); }
int kek(ll a) {
  int num = 0;
  while (a > 0) {
    num += a % 2;
    a /= 2;
  }
  return num;
}
void dfs(vector<vector<int>>& g, int u, vector<int>& color, int curcolor) {
  color[u] = curcolor;
  for (auto v : g[u]) {
    if (color[v] == -1) dfs(g, v, color, curcolor);
  }
}
void gfs(vector<vector<int>>& g, vector<int>& color, int u, bool& f) {
  for (auto v : g[u]) {
    if (color[v] != -1 && color[v] == color[u]) f = false;
    if (color[v] == -1) {
      color[v] = !color[u];
      gfs(g, color, v, f);
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  vector<vector<int>> ng1(n), ng2(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    --x;
    --y;
    g[x].push_back({y, v});
    g[y].push_back({x, v});
    if (v != -1) {
      if (kek(v) % 2 == 0) {
        ng1[x].push_back(y);
        ng1[y].push_back(x);
      } else {
        ng2[x].push_back(y);
        ng2[y].push_back(x);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    --a;
    --b;
    if (p == 0) {
      ng1[a].push_back(b);
      ng1[b].push_back(a);
    } else {
      ng2[a].push_back(b);
      ng2[b].push_back(a);
    }
  }
  vector<int> color(n, -1);
  int cur_color = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      dfs(ng1, i, color, cur_color);
      cur_color++;
    }
  }
  vector<vector<int>> g1(cur_color);
  for (int i = 0; i < n; i++) {
    for (auto v : ng2[i]) {
      g1[color[i]].push_back(color[v]);
    }
  }
  vector<int> color1(cur_color, -1);
  for (int i = 0; i < cur_color; i++) {
    if (color1[i] == -1) {
      color1[i] = 0;
      bool f = 1;
      gfs(g1, color1, i, f);
      if (!f) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  set<pair<int, int>> e;
  for (int i = 0; i < n; i++) {
    for (auto p : g[i]) {
      int v = p.first;
      if (e.count({i, v}) == 0) {
        if (p.second != -1) {
          cout << i + 1 << ' ' << v + 1 << ' ' << p.second << '\n';
        } else {
          int a = (color1[color[i]] != color1[color[v]]);
          cout << i + 1 << ' ' << v + 1 << ' ' << a << '\n';
        }
        e.insert({i, v});
        e.insert({v, i});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rnd = mt19937(956231);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
