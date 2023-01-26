#include <bits/stdc++.h>
using namespace std;
long long in_time[200005];
long long a[200005];
long long out_time[200005];
long long depth[200005];
long long tim = 1, n;
long long bit[2000005];
vector<long long> adj[200005];
long long par[200005][25];
void upd(long long ind, long long v, long long n) {
  while (ind <= n) {
    bit[ind] += v;
    ind += (ind & (-ind));
  }
}
long long query(long long ind) {
  long long s = 0;
  while (ind > 0) {
    s += bit[ind];
    ind -= (ind & (-ind));
  }
  return s;
}
void dfs(long long v, long long p) {
  depth[v] = depth[p] + 1;
  par[v][0] = p;
  in_time[v] = tim++;
  upd(in_time[v], a[v], 2 * n);
  for (long long i = 1; i <= 20; i++) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (auto to : adj[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
  out_time[v] = tim++;
  upd(out_time[v], -a[v], 2 * n);
}
long long lca(long long u, long long v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  long long diff = abs(depth[u] - depth[v]);
  for (long long i = 0; i <= 20; i++) {
    if (diff & (1ll << i)) {
      v = par[v][i];
    }
  }
  if (u == v) {
    return v;
  }
  for (long long i = 20; i >= 0; i--) {
    if (par[u][i] == par[v][i]) {
      continue;
    }
    u = par[u][i];
    v = par[v][i];
  }
  return par[u][0];
}
void solve(long long tc) {
  long long q, x, y;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (long long i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  long long ty;
  while (q--) {
    cin >> ty >> x >> y;
    if (ty == 1) {
      upd(in_time[x], -a[x], 2 * n);
      upd(out_time[x], a[x], 2 * n);
      a[x] = abs(y);
      upd(in_time[x], a[x], 2 * n);
      upd(out_time[x], -a[x], 2 * n);
    } else {
      long long lc = lca(x, y);
      long long d =
          2 * (query(in_time[x]) + query(in_time[y]) - query(in_time[lc]));
      if (x == y) {
        cout << 0 << endl;
      } else {
        cout << d - a[x] - a[y] << endl;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  long long tc = 1;
  while (t--) {
    solve(tc);
    tc++;
  }
  return 0;
}
