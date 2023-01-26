#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1e5 + 5;
int f[N << 2], p;
int poi[N << 2], cnt;
bool vis[N << 2], can[N << 2];
int to[N << 2], cntt;
int a, b, ans, pp;
bool flg;
inline int Read() {
  char ch;
  int f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void print(const int x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + 48);
  return;
}
inline void Print(const int x, const char ch = '\n') {
  if (x < 0) {
    putchar('-');
    print(-x);
  } else
    print(x);
  putchar(ch);
  return;
}
inline int Quick_Pow(int a, int b) {
  int ss = 1;
  for (; b; b >>= 1) {
    if (b & 1) ss = 1ll * ss * a % Mod;
    a = 1ll * a * a % Mod;
  }
  return ss;
}
int rb, cb, rd, cd, n, m;
int dr, dc;
inline int Now() {
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
  for (register int i = 1; i <= 4 * n * m; i++) {
    vis[i] = 0;
    can[i] = 0;
  }
  if (dr + rb > n || dr + rb < 1) dr = -dr;
  if (dc + cb > m || dc + cb < 1) dc = -dc;
  int u = Now();
  if (rb == rd || cb == cd) can[u] = 1;
  flg = can[u];
  ans = 0;
  rb += dr, cb += dc;
  while (1) {
    if (dr + rb > n || dr + rb < 1) dr = -dr;
    if (dc + cb > m || dc + cb < 1) dc = -dc;
    int u = Now();
    if (vis[u]) {
      for (register int i = cntt; to[i] != u; i--) poi[++cnt] = to[i];
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
  ans = 0;
  pp = 1;
  int ti = 1;
  if (flg) ti = 0;
  for (register int i = 1; to[i] != poi[cnt]; i++) {
    ans = (ans + 1ll * pp * can[to[i]] * p * ti % Mod) % Mod;
    pp = 1ll * pp * (1 - p + Mod) * can[i] % Mod;
    ti++;
  }
  reverse(poi + 1, poi + cnt + 1);
  a = 1, b = 0;
  for (register int i = cnt; i; i--) {
    int las = i + 1;
    if (i == cnt) las = 1;
    int u = poi[las];
    int ppp = can[poi[i]] * p;
    a = 1ll * a * (1 - ppp + Mod) % Mod;
    b = 1ll * b * (1 - ppp + Mod) % Mod;
    b = (b + 1) % Mod;
  }
  int x = 1ll * b * Quick_Pow(1 - a + Mod, Mod - 2) % Mod;
  ans = (ans + 1ll * pp * (ti + x) % Mod) % Mod;
  ans = (ans - 1 + Mod) % Mod;
  Print(ans);
  return;
}
int T;
int main() {
  for (T = Read(); T; T--) {
    Init();
    Solve();
  }
  return 0;
}
