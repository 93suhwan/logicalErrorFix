#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > adj[200001];
long long visited[200001];
vector<long long> store;
long long dfs(long long cur, long long x) {
  if (visited[cur] != -1) return (visited[cur] == x) ? 0 : -1;
  store.push_back(cur);
  long long impostor;
  visited[cur] = impostor = x;
  for (long long i = 0; i < adj[cur].size(); i++) {
    long long buffer = dfs(adj[cur][i].first, adj[cur][i].second ^ x);
    impostor += buffer;
    if (buffer == -1) return buffer;
  }
  return impostor;
}
void solve() {
  long long n, m, x, y, cnt = 0;
  string tar;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) visited[i] = -1, adj[i].clear();
  for (long long i = 0; i < m; i++) {
    cin >> x >> y >> tar;
    if (tar == "imposter")
      adj[x].push_back({y, 1}), adj[y].push_back({x, 1});
    else
      adj[x].push_back({y, 0}), adj[y].push_back({x, 0});
  }
  for (long long i = 1; i <= n; i++) {
    if (visited[i] != -1) continue;
    store.clear();
    long long c1 = dfs(i, 1);
    for (long long j = 0; j < store.size(); j++) visited[store[j]] = -1;
    store.clear();
    long long c2 = dfs(i, 0);
    if (c1 + c2 == -2) {
      cout << "-1\n";
      return;
    }
    cnt += max(c1, c2);
  }
  cout << cnt << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
