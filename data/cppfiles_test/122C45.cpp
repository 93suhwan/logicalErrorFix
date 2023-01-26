#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const long double PI = acos(-1);
vector<vector<pair<int, int> > > g;
vector<bool> visto, color;
bool dfs(int u, int c = 0) {
  bool ans = true;
  if (visto[u]) return (color[u] == c);
  visto[u] = true;
  color[u] = c;
  for (auto [v, w] : g[u]) {
    ans &= dfs(v, (w ? !c : c));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, p;
    cin >> n >> m;
    g.assign(n + 1, vector<pair<int, int> >());
    visto.assign(n + 1, false);
    color.assign(n + 1, false);
    vector<tuple<int, int, int> > ans(n - 1), choose;
    vector<pair<int, int> > equal, diff;
    for (int i = 0; i < n - 1; i++) {
      cin >> a >> b >> p;
      if (p == -1)
        choose.push_back({a, b, i});
      else if (__builtin_popcount(p) % 2 == 0) {
        g[b].push_back({a, 0});
        g[a].push_back({b, 0});
        ans[i] = {a, b, p};
      } else {
        g[b].push_back({a, 1});
        g[a].push_back({b, 1});
        ans[i] = {a, b, p};
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> p;
      if (p == 0) {
        g[b].push_back({a, 0});
        g[a].push_back({b, 0});
      } else {
        g[b].push_back({a, 1});
        g[a].push_back({b, 1});
      }
    }
    bool pos = true;
    for (int i = 1; i <= n; i++) {
      if (!visto[i]) pos &= dfs(i);
    }
    if (!pos) {
      cout << "NO\n";
      continue;
    }
    for (auto [a, b, id] : choose) {
      bool eq = color[a] == color[b];
      if (eq)
        ans[id] = {a, b, 0};
      else
        ans[id] = {a, b, 1};
    }
    cout << "YES\n";
    for (auto [a, b, p] : ans) cout << a << " " << b << " " << p << '\n';
  }
  return 0;
}
