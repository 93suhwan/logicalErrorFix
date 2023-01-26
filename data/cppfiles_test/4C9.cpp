#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T> A) {
  for (auto I : A) out << I << " ";
  return out;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const int N = 2e5 + 5, mod = 1e9 + 7;
vector<pair<int, int> > E[N];
int n, k, val[N], ans, c[2][N], d[2][N], L[N], R[N], dft, re[N], cost[N], V[N];
void add(int c[], int i, int x) {
  for (; i <= n; i += i & -i) {
    c[i] += x;
    if (c[i] >= mod) c[i] -= mod;
    if (c[i] < 0) c[i] += mod;
  }
}
int query(int c[], int i) {
  int s = 0;
  for (; i > 0; i -= i & -i) {
    s += c[i];
    if (s >= mod) s -= mod;
  }
  return s;
}
namespace Divide {
int dp[N], S, F[N], root, vis[N], siz[N];
void init(int n) { S = n, root = 0, dp[0] = 1e9; }
void getroot(int u, int pre) {
  siz[u] = 1, dp[u] = 0;
  for (auto& e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == pre || vis[v]) continue;
    getroot(v, u);
    siz[u] += siz[v];
    dp[u] = max(dp[u], siz[v]);
  }
  dp[u] = max(dp[u], S - siz[u]);
  if (dp[root] > dp[u]) root = u;
}
void dfs(int u, int pre, int las) {
  L[u] = ++dft, re[dft] = u;
  for (auto& e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v] || v == pre) continue;
    cost[v] = cost[u] + (las != w);
    V[v] = V[u] + val[v];
    if (V[v] >= mod) V[v] -= mod;
    dfs(v, u, w);
  }
  R[u] = dft;
}
void solve(int u) {
  cost[u] = dft = 0;
  V[u] = val[u];
  dfs(u, 0, -1);
  for (auto& e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v]) continue;
    for (int i = L[v]; i <= R[v]; i++) {
      int need = k - cost[re[i]];
      if (need >= 0) {
        ans += V[re[i]];
        if (ans >= mod) ans -= mod;
      }
      ans += query(c[w], need + 1);
      if (ans >= mod) ans -= mod;
      ans += (long long)query(d[w], need + 1) * V[re[i]] % mod;
      if (ans >= mod) ans -= mod;
      ans -= (long long)query(d[w], need + 1) * val[u] % mod;
      if (ans < 0) ans += mod;
      ans += query(c[w ^ 1], need);
      if (ans >= mod) ans -= mod;
      ans += (long long)query(d[w ^ 1], need) * V[re[i]] % mod;
      if (ans >= mod) ans -= mod;
      ans -= (long long)query(d[w ^ 1], need) * val[u] % mod;
      if (ans < 0) ans += mod;
    }
    for (int i = L[v]; i <= R[v]; i++)
      add(c[w], cost[re[i]], V[re[i]]), add(d[w], cost[re[i]], 1);
  }
  for (auto& e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v]) continue;
    for (int i = L[v]; i <= R[v]; i++)
      add(c[w], cost[re[i]], -V[re[i]]), add(d[w], cost[re[i]], -1);
  }
}
void dfz(int u) {
  int now = S;
  vis[u] = 1;
  solve(u);
  for (auto& e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v]) continue;
    S = siz[v] > siz[u] ? now - siz[u] : siz[v];
    init(S);
    getroot(v, u);
    dfz(root);
  }
}
}  // namespace Divide
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) cin >> val[i], ans = (ans + val[i]) % mod;
  for (int i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  Divide::init(n);
  Divide::getroot(1, 0);
  Divide::dfz(Divide::root);
  cout << ans << '\n';
  return 0;
}
