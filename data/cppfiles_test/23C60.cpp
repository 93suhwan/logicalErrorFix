#include <bits/stdc++.h>
using namespace std;
namespace IO_BUFF {
const long long BS = (1 << 24) + 5;
char Buffer[BS], *HD, *TL;
inline long long gc() {
  if (HD == TL) TL = (HD = Buffer) + fread(Buffer, 1, BS, stdin);
  return (HD == TL) ? EOF : *HD++;
}
inline long long inn() {
  long long x, ch;
  while ((ch = gc()) < '0' || ch > '9')
    ;
  x = ch ^ '0';
  while ((ch = gc()) >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ '0');
  return x;
}
char ss[19999999], tt[20];
long long ssl, ttl;
inline long long print(long long x) {
  if (x < 0) ss[++ssl] = '-', x = (-x);
  if (!x) ss[++ssl] = '0';
  for (ttl = 0; x; x /= 10) tt[++ttl] = char(x % 10 + '0');
  for (; ttl; ttl--) ss[++ssl] = tt[ttl];
  return ss[++ssl] = '\n';
}
inline long long Flush() {
  return fwrite(ss + 1, sizeof(char), ssl, stdout), ssl = 0, 0;
}
long long read() {
  char c = getchar();
  long long x = 1;
  long long s = 0;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
}  // namespace IO_BUFF
using namespace IO_BUFF;
const long long N = 4055;
long long n, m, a[N], rt, ch[N][2], siz[N], f[N][N];
void work(long long &u, long long l, long long r) {
  if (l > r) {
    u = 0;
    return;
  }
  long long maxx = 1e15, jl = -1;
  for (long long i = l; i <= r; i++) {
    if (a[i] < maxx) maxx = a[i], jl = i;
  }
  u = jl;
  work(ch[u][0], l, jl - 1);
  work(ch[u][1], jl + 1, r);
}
void solve(long long u) {
  memset(f[u], -10, sizeof(f[u]));
  siz[u] = 1;
  f[u][0] = 0;
  f[u][1] = (m - 1) * a[u];
  for (long long i = 0; i <= 1; i++) {
    long long v = ch[u][i];
    if (!v) continue;
    solve(ch[u][i]);
    if (u == 2) {
      new char;
    }
    for (long long k = min(m, siz[u] + siz[ch[u][i]]); k >= 0; k--) {
      for (long long j = max(k - siz[u], 0ll);
           j <= siz[ch[u][i]] && k - j >= 0 && j <= m; j++) {
        f[u][k] =
            max(f[u][k], f[u][k - j] + f[v][j] - 2LL * a[u] * (k - j) * j);
      }
    }
    siz[u] += siz[ch[u][i]];
  }
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
  }
  work(rt, 1, n);
  solve(rt);
  cout << f[rt][m];
  return 0;
}
