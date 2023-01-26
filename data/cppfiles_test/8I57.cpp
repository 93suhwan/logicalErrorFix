#include <bits/stdc++.h>
using namespace std;
const long double PI = atan(1) * 4.0;
const long long N = 2e5 + 5;
const long long LOG = 20;
long long Bit[2 * N];
long long inTime[N], outTime[N], timer = 0, value[N], depth[N], up[N][LOG];
vector<long long> adj[N];
long long n;
long long sum(long long k) {
  long long s = 0;
  while (k >= 1) {
    s += Bit[k];
    k -= k & -k;
  }
  return s;
}
void add(long long k, long long x) {
  while (k <= n) {
    Bit[k] += x;
    k += k & -k;
  }
}
long long get(long long l, long long r) { return sum(r) - sum(l - 1); }
void dfs(long long s, long long p) {
  inTime[s] = ++timer;
  add(inTime[s], value[s]);
  for (long long i = 0; i < adj[s].size(); i++) {
    if (adj[s][i] != p) {
      long long b = adj[s][i];
      depth[b] = depth[s] + 1;
      up[b][0] = s;
      for (long long j = 1; j < LOG; j++) {
        up[b][j] = up[up[b][j - 1]][j - 1];
      }
      dfs(adj[s][i], s);
    }
  }
  outTime[s] = timer;
  add(outTime[s] + 1, -value[s]);
}
long long get_lca(long long a, long long b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }
  long long k = depth[a] - depth[b];
  for (long long j = LOG - 1; j >= 0; j--) {
    if (k & (1 << j)) {
      a = up[a][j];
    }
  }
  if (a == b) {
    return a;
  }
  for (long long j = LOG - 1; j >= 0; j--) {
    if (up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
    }
  }
  return up[a][0];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> value[i];
    value[i] = abs(value[i]);
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  while (q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long k, val;
      cin >> k >> val;
      val = abs(val);
      add(inTime[k], val - value[k]);
      add(outTime[k] + 1, value[k] - val);
      value[k] = val;
    } else {
      long long u, v;
      cin >> u >> v;
      long long lca = get_lca(u, v);
      if (lca == u) {
        cout << 2 * (sum(inTime[v]) - sum(inTime[u]) + value[u]) - value[u] -
                    value[v]
             << '\n';
      } else if (lca == v) {
        cout << 2 * (sum(inTime[u]) - sum(inTime[v]) + value[v]) - value[u] -
                    value[v]
             << '\n';
      } else {
        cout << 2 * (sum(inTime[u]) + sum(inTime[v]) - sum(lca)) - value[u] -
                    value[v]
             << '\n';
      }
    }
  }
  return 0;
}
