#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5;
long long par[MAXN];
long long depth[MAXN];
void dfs(long long u, long long p, const vector<vector<long long>> &adj) {
  par[u] = p;
  for (long long v : adj[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u, adj);
    }
}
void solve() {
  long long nbSommets;
  cin >> nbSommets;
  vector<vector<long long>> adj(nbSommets);
  for (long long i = 1; i < nbSommets; ++i) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<long long> sizes;
  dfs(0, 0, adj);
  vector<bool> blocked(nbSommets);
  vector<long long> order(nbSommets);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(),
       [&](long long u, long long v) { return depth[u] > depth[v]; });
  for (long long u : order) {
    if (!u) break;
    long long cntSons = 0;
    for (long long v : adj[u])
      if (v != par[u] and !blocked[v]) cntSons++;
    if (cntSons > 0) {
      sizes.push_back(cntSons), blocked[u] = true;
    }
  }
  long long rem = 0;
  for (long long u : adj[0])
    if (!blocked[u]) rem++;
  long long tot = 0;
  for (long long x : sizes) tot += x;
  tot += rem;
  tot -= rem ? sizes.size() : sizes.size() - 1;
  cout << tot << '\n';
}
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long nbTests;
  cin >> nbTests;
  for (long long iTest(0); iTest < nbTests; ++iTest) solve();
}
