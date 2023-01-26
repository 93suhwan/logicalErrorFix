#include <bits/stdc++.h>
using namespace std;
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
const long long p = 998244353;
long long qp(long long x, long long y) {
  long long res = 1;
  for (long long t = x; y; y >>= 1, t = t * t % p)
    if (y & 1) res = res * t % p;
  return res;
}
bool vis[100003];
long long x[100003], y[100003], c;
signed main() {
  for (long long T = read(); T--;) {
    long long n = read(), m = read();
    for (long long i = 1; i <= n * 2; ++i) vis[i] = 0;
    for (long long i = 1; i <= m; ++i) {
      x[i] = read(), y[i] = read(), vis[x[i]] = vis[y[i]] = 1;
      if (x[i] > y[i]) swap(x[i], y[i]);
    }
    long long ans = (n - m) * (n - m - 1) / 2;
    for (long long i = 1; i <= m; ++i)
      for (long long j = 1; j <= m; ++j)
        if (i != j) {
          if (x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) ++ans;
        }
    for (long long i = 1; i <= m; ++i) {
      long long cnt = 0;
      for (long long j = x[i] + 1; j < y[i]; ++j)
        if (!vis[j]) ++cnt;
      ans += min(cnt, 2 * (n - m) - cnt);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
