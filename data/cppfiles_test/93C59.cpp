#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 3e5 + 5;
const int base = 350;
const int base2 = 311;
long long n, m, t, k, T, tong, a[N], b[N], c[N], d[N], ans, dp[N], lab[N], h[N],
    P[N][20];
vector<long long> adj[N], kq;
long long pw(long long k, long long n) {
  long long total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = total * k % mod;
    k = k * k % mod;
  }
  return total;
}
string s;
void dfs(long long u, long long p) {
  for (int i = 1; i < 20; i++) P[u][i] = P[P[u][i - 1]][i - 1];
  for (long long v : adj[u]) {
    if (v == p) continue;
    h[v] = h[u] + 1;
    P[v][0] = u;
    dfs(v, u);
  }
}
long long lca(long long u, long long v) {
  if (h[u] < h[v]) swap(u, v);
  long long log = log2(h[u]) + 1;
  for (int i = log; i >= 0; i--) {
    if (h[u] >= h[v] + (1 << i)) u = P[u][i];
  }
  if (u == v) return u;
  for (int i = log; i >= 0; i--) {
    if (P[u][i] && P[u][i] != P[v][i]) {
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}
long long findp(long long u) { return lab[u] < 0 ? u : lab[u] = findp(lab[u]); }
void hop(long long u, long long v) {
  lab[u] += lab[v];
  lab[v] = u;
}
void sol() {
  n = 3e5;
  for (int i = 1; i <= n; i++) a[i] = (a[i - 1] ^ i);
  cin >> t;
  while (t-- > 0) {
    cin >> n >> m;
    if ((m ^ a[n - 1]) == 0)
      cout << n << '\n';
    else if ((m ^ a[n - 1]) != n)
      cout << n + 1 << '\n';
    else
      cout << n + 2 << '\n';
  }
}
int main() {
  if (fopen("INTERNET"
            ".in",
            "r")) {
    freopen(
        "INTERNET"
        ".in",
        "r", stdin);
    freopen(
        "INTERNET"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  while (ntest-- > 0) sol();
}
