#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
inline char gc() {
  if (i_s == i_t) {
    i_s = i_str;
    i_t = i_s + fread(i_str, 1, MAXL, stdin);
    return i_s == i_t ? EOF : *i_s++;
  } else
    return *i_s++;
}
inline int read() {
  int x = 0, f = 0;
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
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
const int N = 5e5 + 5, mod = 998244353;
int D, f[N][3];
inline void Solve() {
  int n = read(), ans = 0;
  for (register int i = 0; i <= n + 2; ++i) f[i][0] = f[i][1] = f[i][2] = 0;
  for (register int i = 1; i <= n; ++i) {
    int x = read();
    f[x + 2][1] = (f[x + 2][1] + f[x + 2][1]) % mod;
    if (!x) {
      f[x][0] = (f[x][0] + f[x][0] + 1) % mod;
      continue;
    }
    f[x][0] = ((f[x][0] + f[x][0]) % mod + f[x - 1][0]) % mod;
    if (x == 1) {
      f[x][1] = (f[x][1] + f[x][1] + 1) % mod;
      continue;
    }
    f[x][1] = ((f[x][1] + f[x][1]) % mod + f[x - 2][0]) % mod;
  }
  for (register int i = 0; i <= n + 2; ++i)
    ans = (((ans + f[i][0]) % mod + f[i][1]) % mod + f[i][2]) % mod;
  write(ans), pc('\n');
  return;
}
signed main() {
  int T = read();
  while (T--) Solve();
  fwrite(o_str, 1, o_t, stdout), o_t = 0;
  return 0;
}
