#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
const long long N = 1e5 + 5;
long long f[N << 2], p;
long long poi[N << 2], cnt;
bool vis[N << 2], can[N << 2];
long long to[N << 2], cntt;
long long a, b, ans, pp;
bool flg;
inline long long Read() {
  char ch;
  long long f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  long long x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void print(const long long x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + 48);
  return;
}
inline void Print(const long long x, const char ch = '\n') {
  if (x < 0) {
    putchar('-');
    print(-x);
  } else
    print(x);
  putchar(ch);
  return;
}
inline long long Quick_Pow(long long a, long long b) {
  long long ss = 1;
  for (; b; b >>= 1) {
    if (b & 1) ss = 1ll * ss * a % Mod;
    a = 1ll * a * a % Mod;
  }
  return ss;
}
long long rb, cb, rd, cd, n, m;
long long dr, dc;
inline long long Now() {
  if (dr == 1 && dc == 1) return (rb - 1) * m + cb;
  if (dr == 1 && dc == -1) return (rb - 1) * m + cb + n * m;
  if (dr == -1 && dc == 1) return (rb - 1) * m + cb + 2 * n * m;
  return (rb - 1) * m + cb + 3 * n * m;
}
inline void Init() {
  dr = 1, dc = 1;
  n = Read();
  m = Read();
  rb = Read();
  cb = Read();
  rd = Read();
  cd = Read();
  p = Read();
  p = 1ll * p * Quick_Pow(100, Mod - 2) % Mod;
  cnt = cntt = 0;
  for (register long long i = 1; i <= 4 * n * m; i++) {
    vis[i] = 0;
    can[i] = 0;
  }
  ans = 0;
  while (1) {
    if (dr + rb > n || dr + rb < 1) dr = -dr;
    if (dc + cb > m || dc + cb < 1) dc = -dc;
    long long u = Now();
    if (vis[u]) {
      for (register long long i = cntt; to[i] != u; i--) poi[++cnt] = to[i];
      poi[++cnt] = u;
      break;
    }
    if (rb == rd || cb == cd) can[u] = 1;
    to[++cntt] = u;
    vis[u] = 1;
    rb += dr, cb += dc;
  }
  return;
}
inline void Solve() {
  reverse(poi + 1, poi + cnt + 1);
  ans = 0;
  a = 1, b = 0;
  for (register long long i = cnt; i; i--) {
    long long pp = can[poi[i]] * p;
    a = 1ll * a * (1 - pp + Mod) % Mod;
    b = 1ll * b * (1 - pp + Mod) % Mod;
    b = (b + 1) % Mod;
  }
  long long x = 1ll * b * Quick_Pow(1 - a + Mod, Mod - 2) % Mod;
  ans = x;
  ans = (ans - 1 + Mod) % Mod;
  Print(ans);
  return;
}
long long T;
signed main() {
  for (T = Read(); T; T--) {
    Init();
    Solve();
  }
  return 0;
}
