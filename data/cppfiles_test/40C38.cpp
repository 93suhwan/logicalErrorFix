#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
vector<int> g[maxn], t[maxn];
int tin[maxn], tout[maxn], p[maxn];
int tmr = 0;
void dfs(int v, int pr) {
  p[v] = pr;
  tin[v] = tmr;
  ++tmr;
  for (auto u : t[v]) {
    if (u == pr) continue;
    dfs(u, v);
  }
  tout[v] = tmr;
}
vector<int> get(int v, int u) {
  int tv = v;
  vector<int> ans = {v};
  while (tin[tv] > tin[u] || tout[tv] < tout[u]) {
    tv = p[tv];
    ans.push_back(tv);
  }
  vector<int> kek;
  int tu = u;
  while (tu != tv) {
    kek.push_back(tu);
    tu = p[tu];
  }
  reverse(kek.begin(), kek.end());
  for (auto el : kek) ans.push_back(el);
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  int q;
  cin >> q;
  int cnt = 0;
  vector<int> fl(n);
  vector<pair<int, int> > qs;
  while (q) {
    --q;
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    fl[v] ^= 1;
    fl[u] ^= 1;
    if (fl[v])
      ++cnt;
    else
      --cnt;
    if (fl[u])
      ++cnt;
    else
      --cnt;
    qs.push_back({v, u});
  }
  if (cnt) {
    cout << "NO\n" << cnt / 2;
    return;
  }
  cout << "YES\n";
  vector<int> ws(n);
  ws[0] = 1;
  queue<int> qu;
  qu.push(0);
  while (!qu.empty()) {
    int v = qu.front();
    qu.pop();
    for (auto u : g[v]) {
      if (!ws[u]) {
        ws[u] = 1;
        qu.push(u);
        t[v].push_back(u);
        t[u].push_back(v);
      }
    }
  }
  dfs(0, -1);
  for (auto el : qs) {
    auto ans = get(el.first, el.second);
    cout << ans.size() << '\n';
    for (auto el1 : ans) cout << el1 + 1 << ' ';
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
