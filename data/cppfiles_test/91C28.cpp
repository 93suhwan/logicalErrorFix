#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
namespace FastIO {
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar('\n'), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar('\n');
  return;
}
}  // namespace FastIO
using namespace FastIO;
const long long mod = 998244353;
inline long long add(long long x, long long y, long long Mod = mod) {
  return x + y >= Mod ? x + y - Mod : x + y;
}
inline long long del(long long x, long long y, long long Mod = mod) {
  return x - y < 0 ? x - y + Mod : x - y;
}
inline long long mul(long long x, long long y, long long Mod = mod) {
  return x * y - x * y / Mod * Mod;
}
inline void ckadd(long long &x, long long y, long long Mod = mod) {
  x = x + y >= Mod ? x + y - Mod : x + y;
}
inline void ckdel(long long &x, long long y, long long Mod = mod) {
  x = x - y < 0 ? x - y + Mod : x - y;
}
inline void ckmul(long long &x, long long y, long long Mod = mod) {
  x = x * y - x * y / Mod * Mod;
}
inline long long ksm(long long x, long long y, long long Mod = mod) {
  long long res = 1;
  for (; y; y >>= 1, ckmul(x, x, Mod))
    if (y & 1) ckmul(res, x, Mod);
  return res;
}
inline void approx(long long val, long long Mod = mod, long long lim = 1e5) {
  long long x = val, y = Mod, a = 1, b = 0;
  while (x > lim) {
    swap(x, y);
    swap(a, b);
    a -= x / y * b;
    x %= y;
  }
  cout << x << "/" << a << endl;
  return;
}
const long long N = 1e5 + 10;
long long dp[2][N], vis[2][N], a[N], n;
vector<long long> app[2];
inline void insert(long long cur, long long val) {
  if (!vis[cur][val]) vis[cur][val] = 1, app[cur].push_back(val);
  return;
}
signed main() {
  long long T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; ++i) a[i] = read();
    long long cur = 0, ans = 0;
    for (long long i = n; i >= 1; --i, cur ^= 1) {
      ckadd(dp[cur][a[i]], 1);
      insert(cur, a[i]);
      for (auto t : app[cur ^ 1]) {
        long long k = (a[i] + t - 1) / t;
        ckadd(dp[cur][a[i] / k], dp[cur ^ 1][t]);
        insert(cur, a[i] / k);
        ckadd(ans, mul(i, mul(dp[cur ^ 1][t], k - 1)));
        dp[cur ^ 1][t] = vis[cur ^ 1][t] = 0;
      }
      app[cur ^ 1].clear();
    }
    cur ^= 1;
    for (auto t : app[cur]) vis[cur][t] = dp[cur][t] = 0;
    app[cur].clear();
    print(ans);
  }
  return 0;
}
