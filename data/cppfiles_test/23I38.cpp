#include <bits/stdc++.h>
const long long mod = 998244353;
long long Add(long long x, long long y) {
  return (x + y >= mod) ? (x + y - mod) : (x + y);
}
long long Mul(long long x, long long y) { return x * y % mod; }
long long Mod(long long x) {
  return x < 0 ? (x + mod) : (x >= mod ? (x - mod) : x);
}
long long cadd(long long &x, long long y) {
  return x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T &read(T &r) {
  r = 0;
  bool w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') w = ch == '-' ? 1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') r = r * 10 + (ch ^ 48), ch = getchar();
  return r = w ? -r : r;
}
const int N = 4010;
int n, m, ls[N], rs[N], st[N], top, a[N], siz[N];
long long f[N][N];
std::vector<int> eg[N];
void dfs(int x) {
  siz[x] = 1;
  for (auto v : eg[x]) dfs(v);
  f[x][1] = 1ll * (m - 1) * a[x];
  for (auto v : eg[x]) {
    for (int j = Min(siz[x] + siz[v], m); j >= 0; --j)
      for (int k = Max(0, j - siz[x] - 1); k <= Min(j, siz[v]); ++k) {
        if (j - k >= 0)
          f[x][j] =
              Max(f[x][j], f[v][k] + f[x][j - k] - 2ll * k * (j - k) * a[x]);
        if (j - k - 1 >= 0)
          f[x][j] =
              Max(f[x][j], f[v][k] + f[x][j - k - 1] -
                               2ll * k * (j - k - 1) * a[x] -
                               2ll * (j - 1) * a[x] + 1ll * (m - 1) * a[x]);
      }
    siz[x] += siz[v];
  }
}
signed main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    int k = top;
    while (k && a[st[k]] > a[i]) --k;
    if (k) rs[st[k]] = i;
    if (k < top) ls[i] = st[k + 1];
    st[top = k + 1] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (ls[i]) eg[i].emplace_back(ls[i]);
    if (rs[i]) eg[i].emplace_back(rs[i]);
  }
  dfs(st[1]);
  printf("%lld\n", f[st[1]][m]);
  return 0;
}
