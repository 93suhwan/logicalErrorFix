#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long N = 2e5 + 5;
long long a[N], b[N], k[N], n, h[N];
vector<long long> d[N];
set<int> g[N];
bool vis[N];
long long bfs(long long first) {
  queue<int> q;
  q.push(first);
  h[first] = 1;
  long long ans = 0;
  while (q.size()) {
    long long u = q.front();
    q.pop();
    ans = max(ans, h[u]);
    for (int v : d[u]) {
      g[v].erase(u);
      h[v] = max(h[v], h[u] + (v < u));
      if (vis[v] == false && g[v].size() == 0)
        h[v] = max(h[v], h[u] + (v < u)), q.push(v);
    }
  }
  return ans;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) d[i].clear(), h[i] = 0, g[i].clear(), vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    for (int j = 1, u; j <= k[i]; j++) {
      cin >> u;
      d[u].push_back(i);
      g[i].insert(u);
    }
  }
  long long ans = -1;
  for (int i = 1; i <= n; i++)
    if (k[i] == 0) {
      ans = max(ans, bfs(i));
    }
  for (int i = 1; i <= n; i++)
    if (g[i].size() > 0) ans = -1;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
