#include <bits/stdc++.h>
using namespace std;
const long long MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
long long o_t;
inline char gc() {
  if (i_s == i_t) {
    i_s = i_str;
    i_t = i_s + fread(i_str, 1, MAXL, stdin);
    return i_s == i_t ? EOF : *i_s++;
  } else
    return *i_s++;
}
inline long long read() {
  long long x = 0, f = 0;
  char ch = gc();
  for (; ch < '0' || ch > '9'; ch = gc())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = gc()) x = x * 10 + (ch ^ 48);
  return f ? -x : x;
}
inline void pc(char x) {
  o_str[o_t++] = x;
  if (o_t == MAXL) fwrite(o_str, 1, o_t, stdout), o_t = 0;
}
void write(long long x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
const long long N = 5e5 + 5, mod = 998244353;
using namespace std;
long long m, n, p, k, now = 1, tot, r = 0, Min[N], g[N], a[N], f[N];
inline void TryInsert(long long x) {
  long long s = 0;
  while (r > 0) {
    if (Min[r] >= x)
      (s += (mod + 1ll * now * g[r]) % mod) %= mod,
          (tot += (mod - 1ll * now * g[r] * Min[r] % mod) % mod) %= mod, --r;
    else
      break;
  }
  Min[++r] = x;
  g[r] = (mod + 1ll * now * s) % mod;
  (tot += (mod + 1ll * now * g[r] * Min[r] % mod) % mod) %= mod;
  return;
}
inline void InsertItem(long long x) {
  (tot += (mod - 1ll * now * g[r] * Min[r] % mod) % mod) %= mod;
  (g[r] += (mod + x * now) % mod) %= mod;
  (tot += (mod + 1ll * now * g[r] * Min[r] % mod) % mod) %= mod;
  return;
}
inline long long Mini(long long x, long long y) {
  long long s = a[x];
  for (register long long i = x; i <= y; ++i) s = min(s, a[i]);
  return s;
}
signed main() {
  n = read();
  for (register long long i = 1; i <= n; ++i) a[i] = read();
  f[0] = 1;
  for (register long long i = 1; i <= n; ++i) {
    TryInsert(a[i]);
    f[i] = 1ll * f[i - 1] * a[i] % mod;
    (f[i] += tot) %= mod;
    InsertItem(f[i - 1]);
    now *= -1;
    tot = (mod - tot) % mod;
  }
  write(f[n] % mod), pc('\n'), fwrite(o_str, 1, o_t, stdout), o_t = 0;
  return 0;
}
