#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long N = 100 + 5;
struct binary_lifting {
  const long long lg = 24;
  long long n;
  vector<vector<long long>> edges, anc;
  vector<long long> depth;
  void init(long long s) {
    n = s;
    for (long long i = 1; i < n + 1; i++) edges.clear();
    edges.resize(n);
    anc.resize(n, vector<long long>(lg));
    depth.resize(n, 0);
  }
  void edge(long long a, long long b) {
    edges[a].push_back(b), edges[b].push_back(a);
  }
  void attach(long long node_to_attach, long long node_to_attach_to) {
    long long a = node_to_attach, b = node_to_attach_to;
    edge(a, b);
    anc[a][0] = b;
    depth[a] = 1 + depth[b];
    for (long long i = 1; i < lg; i++) anc[a][i] = anc[anc[a][i - 1]][i - 1];
  }
  void init_lift(long long v = 1) { dfs(v, 0); }
  void dfs(long long z, long long p) {
    anc[z][0] = p;
    if (p) depth[z] = 1 + depth[p];
    for (long long i = 1; i < 18; i++) anc[z][i] = anc[anc[z][i - 1]][i - 1];
    for (long long x : edges[z])
      if (x != p) dfs(x, z);
  }
  long long up(long long z, long long l) {
    if (l == 0) return z;
    return up(anc[z][__builtin_ctz(l)], l - (l & -l));
  }
  long long lca(long long u, long long v) {
    if (depth[u] > depth[v]) swap(u, v);
    long long d = depth[v] - depth[u];
    v = up(v, d);
    if (u == v) return u;
    for (long long i = 17; i >= 0; i--)
      if (anc[u][i] != anc[v][i]) return lca(anc[u][i], anc[v][i]);
    assert(anc[u][0] == anc[v][0]);
    return anc[u][0];
  }
  long long dist(long long u, long long v) {
    long long lc = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lc];
  }
};
long long fac[N + 1], invfac[N + 1];
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= 1000000007;
    }
    a *= a;
    a %= 1000000007;
    b >>= 1;
  }
  return res;
}
void init() {
  fac[0] = 1;
  for (long long i = 1; i < N + 1; i++) {
    fac[i] = i * fac[i - 1] % 1000000007;
  }
  invfac[N] = binpow(fac[N], 1000000007 - 2);
  for (long long i = N - 1; i >= 0; i--) {
    invfac[i] = (invfac[i + 1] * (i + 1)) % 1000000007;
  }
}
long long ncr(long long n, long long r) {
  if (r < 0 || n < 0 || r > n) return 0;
  return ((fac[n] * invfac[r] % 1000000007) * invfac[n - r] % 1000000007);
}
binary_lifting lca;
long long n, m, k, p[N][N][N];
void test_case() {
  cin >> n >> k;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 0; j < n; j++)
      for (long long k = 1; k < n + 1; k++) p[i][j][k] = 0;
  lca.init(n + 1);
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    lca.edge(x, y);
    ;
  }
  if (k == 2) {
    cout << ncr(n, 2) << endl;
    return;
  }
  lca.init_lift();
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = i + 1; j < n + 1; j++) {
      if (lca.depth[i] == lca.depth[j]) {
        long long tmp = lca.lca(i, j);
        p[tmp][lca.depth[i]][i] = 1;
        p[tmp][lca.depth[i]][j] = 1;
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = lca.depth[i] + 1; j < n; j++) {
      long long cnt = 0;
      for (long long k = 1; k < n + 1; k++) cnt += p[i][j][k];
      if (lca.depth[i] >= (j - lca.depth[i])) cnt++;
      ans = (ans + ncr(cnt, k)) % 1000000007;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    test_case();
  }
  return 0;
}
