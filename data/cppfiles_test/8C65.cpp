#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long inf = 0x3f3f3f3f;
const int LOG = 20;
int n, q, timer, w[N], in[N], out[N];
long long a[N], T[N];
vector<int> adj[N];
void update(int pos, int v) {
  for (; pos <= n; pos += pos & -pos) T[pos] += v;
}
long long get(int pos) {
  long long res = 0;
  for (; pos > 0; pos -= pos & -pos) res += T[pos];
  return res;
}
int h[N], P[N][LOG];
void dfs(int u, int p) {
  in[u] = ++timer;
  for (int v : adj[u])
    if (v ^ p) h[v] = h[u] + 1, P[v][0] = u, dfs(v, u);
  out[u] = timer;
}
void buildLCA(int s) {
  h[s] = 0, dfs(s, s);
  for (int j = 1; (1 << j) <= n; j++)
    for (long long i = (1); i < (n + 1); i++)
      if (P[i][j - 1]) P[i][j] = P[P[i][j - 1]][j - 1];
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int hu = h[u], hv = h[v];
  int log = log2(h[u]);
  for (long long i = (log); i >= (0); i--)
    if (h[u] - (1 << i) >= h[v]) u = P[u][i];
  if (u == v) return u;
  for (long long i = (log); i >= (0); i--)
    if (P[u][i] && P[u][i] != P[v][i]) u = P[u][i], v = P[v][i];
  return P[u][0];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> q;
  for (long long i = (1); i < (n + 1); i++) cin >> a[i], a[i] = abs(a[i]);
  for (long long i = (1); i < (n); i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  buildLCA(1);
  for (long long i = (1); i < (n + 1); i++)
    update(in[i], a[i]), update(out[i] + 1, -a[i]);
  while (q--) {
    int type, u, v;
    cin >> type >> u >> v;
    if (type == 1) {
      update(in[u], -a[u]), update(out[u] + 1, a[u]);
      a[u] = abs(v);
      update(in[u], a[u]), update(out[u] + 1, -a[u]);
    } else {
      int s = LCA(u, v);
      long long ans = 2 * (get(in[u]) + get(in[v]) - 2 * get(in[s])) +
                      2 * a[s] - a[u] - a[v];
      cout << ans << endl;
    }
  }
}
