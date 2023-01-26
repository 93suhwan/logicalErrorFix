#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<pair<int, int> > adjT;
int valadjT[N];
int mark[N];
vector<pair<int, int> > adj[N];
int n, m;
bool bit(int i, int j) { return ((j >> i) & 1); }
bool num(int X) {
  bool rt = 0;
  for (int j = 0; j <= 31; j++)
    if (bit(j, X)) rt = !rt;
  return rt;
}
void dfs(int v, int val) {
  mark[v] = val;
  for (pair<int, int> x0 : adj[v]) {
    int u = x0.first;
    int valp = val + x0.second;
    valp %= 2;
    if (mark[u] == -1) dfs(u, valp);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) mark[i] = -1;
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
  adjT.clear();
  for (int i = 0; i <= n - 2; i++) {
    int u, v, V;
    cin >> u >> v >> V;
    if (V != -1) {
      adj[u].push_back({v, num(V)});
      adj[v].push_back({u, num(V)});
    }
    adjT.push_back({u, v});
    valadjT[i] = V;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, p;
    cin >> u >> v >> p;
    adj[u].push_back({v, p});
    adj[v].push_back({u, p});
  }
  for (int i = 1; i <= n; i++)
    if (mark[i] == -1) dfs(i, 0);
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> x0 : adj[i]) {
      int v = x0.first;
      if ((mark[i] != mark[v]) != (x0.second)) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i <= n - 2; i++) {
    int u = adjT[i].first;
    int v = adjT[i].second;
    if (valadjT[i] == -1) {
      valadjT[i] = (mark[u] != mark[v]);
    }
    cout << u << " " << v << " " << valadjT[i] << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
