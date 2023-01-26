#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long long N = 2e6 + 5;
const long long M = 70;
const long long SZ = 450;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long inv[N], fac[N], ifc[N];
void Init(long long n) {
  inv[1] = 1;
  for (long long i = 2; i <= n; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifc[0] = 1;
  for (long long i = 1; i <= n; i++) ifc[i] = ifc[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * ifc[m] % mod * ifc[n - m] % mod;
}
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
long long n;
vector<long long> T[N];
long long Fa[N], hs[N];
void dfs(long long u, long long fa) {
  hs[u] = 0;
  Fa[u] = fa;
  for (long long v : T[u]) {
    if (v == fa) continue;
    dfs(v, u);
    hs[u] += !hs[v];
  }
}
long long solve() {
  long long ans = hs[1], f = hs[1];
  for (long long i = 2; i <= n; i++)
    if (hs[i]) {
      if (f)
        ans += hs[i] - 1;
      else
        f = 1, ans += hs[i];
    }
  return ans;
}
signed main() {
  long long JYZ;
  JYZ = read();
  while (JYZ--) {
    n = read();
    for (long long i = 1; i <= n; i++) T[i].clear();
    for (long long i = 1, x, y; i < n; i++)
      x = read(), y = read(), T[x].push_back(y), T[y].push_back(x);
    dfs(1, 0);
    cout << solve() << "\n";
  }
}
