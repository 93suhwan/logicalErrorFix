#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, K, m, rt, a[500000], f[2][500000], g[2][500000], sz[500000],
    mx[500000], vis[500000], ans;
vector<long long> e[500000][2];
void add(long long u, long long fa, long long num, long long sum, long long col,
         long long fst) {
  sum += a[u];
  (f[fst][num] += sum) %= mod;
  ++g[fst][num];
  m = max(m, num);
  for (long long op : {0, 1}) {
    for (long long v : e[u][op]) {
      if (v != fa && !vis[v]) {
        add(v, u, num + (op != col), sum, op, fst);
      }
    }
  }
}
void upd(long long k, long long val) {
  for (long long i = 1; i <= m; ++i) {
    g[0][i] += g[0][i - 1];
    g[1][i] += g[1][i - 1];
  }
  if (val != -1) ans += (g[0][min(K, m)] + g[1][min(K, m)]) * val * k % mod;
  for (long long op : {0, 1}) {
    for (long long i = 1; i <= m; ++i) {
      ans += k * f[op][i] * g[op][min(K - i + 1, m)] % mod;
      ans += k * f[op][i] * g[op ^ 1][min(K - i, m)] % mod;
      if (i <= K && val != -1) ans += f[op][i] * k;
    }
  }
  ans %= mod;
  for (long long i = 1; i <= m; ++i) f[0][i] = f[1][i] = g[0][i] = g[1][i] = 0;
}
void calc(long long u, long long fa, long long num) {
  mx[u] = 0;
  for (long long op : {0, 1}) {
    for (long long v : e[u][op]) {
      if (!vis[v] && v != fa) {
        calc(v, u, num);
        mx[u] = max(mx[u], sz[v]);
      }
    }
  }
  mx[u] = max(mx[u], num - sz[u]);
  if (mx[u] < mx[rt]) rt = u;
}
void dfs(long long u, long long fa) {
  sz[u] = 1;
  for (long long op : {0, 1}) {
    for (long long v : e[u][op]) {
      if (!vis[v] && v != fa) {
        dfs(v, u);
        sz[u] += sz[v];
      }
    }
  }
}
void solve(long long x) {
  vis[x] = 1;
  m = 0;
  for (long long op : {0, 1}) {
    for (long long v : e[x][op])
      if (!vis[v]) {
        add(v, 0, 1, a[x] / 2, op, op);
      }
  }
  upd(1, a[x] / 2);
  for (long long op : {0, 1}) {
    m = 0;
    for (long long v : e[x][op])
      if (!vis[v]) {
        add(v, 0, 1, a[x] / 2, op, op);
        upd(-1, -1);
      }
  }
  for (long long op : {0, 1}) {
    for (long long v : e[x][op])
      if (!vis[v]) {
        rt = 0;
        dfs(v, 0);
        calc(v, 0, sz[v]);
        solve(rt);
      }
  }
}
int main() {
  scanf("%lld%lld", &n, &K);
  ++K;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    a[i] *= 2;
    ans += a[i];
  }
  for (long long i = 1; i < n; ++i) {
    long long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    e[x][z].push_back(y);
    e[y][z].push_back(x);
  }
  mx[rt = 0] = n + 1;
  dfs(1, 0);
  calc(1, 0, sz[1]);
  solve(rt);
  (ans += mod) %= mod;
  ans = ans * ((mod + 1) / 2) % mod;
  printf("%lld\n", ans);
  return 0;
}
