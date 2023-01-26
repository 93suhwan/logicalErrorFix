#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long N = 400007;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long fa[N];
long long find(long long x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
long long merge(long long x, long long y) {
  long long xx = find(x), yy = find(y);
  if (xx == yy) return 0;
  fa[xx] = yy;
  return 1;
}
long long prime[5000007], sz;
bitset<10000007> vis;
void get_prime() {
  vis[1] = 1;
  for (long long i = (2); i <= (10000006); ++i) {
    if (!vis[i]) prime[++sz] = i;
    for (long long j = (1); j <= (sz); ++j) {
      if (i * prime[j] > 10000006) break;
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
long long T, n, m;
char s[N];
long long g[5007][5007];
long long dp[N];
void solve() {
  n = read();
  scanf("%s", s + 1);
  for (long long i = (1); i <= (n + 1); ++i)
    for (long long j = (1); j <= (n + 1); ++j) g[i][j] = 0;
  for (long long i = (1); i <= (n); ++i) dp[i] = n - i + 1;
  for (long long i = (n); i >= (1); --i)
    for (long long j = (n); j >= (1); --j) {
      if (s[i] == s[j])
        g[i][j] = g[i + 1][j + 1] + 1;
      else
        g[i][j] = 0;
    }
  for (long long i = (1); i <= (n); ++i)
    for (long long j = (1); j <= (i - 1); ++j) {
      if (i + g[i][j] <= n and s[i + g[i][j]] > s[j + g[i][j]])
        dp[i] = max(dp[i], dp[j] + n - i - g[i][j] + 1);
    }
  printf("%lld\n", *max_element(dp + 1, dp + 1 + n));
}
signed main() {
  T = read();
  while (T--) solve();
}
