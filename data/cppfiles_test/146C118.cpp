#include <bits/stdc++.h>
namespace cltstream {
char cltin[1048576 + 1], *ih = cltin, *it = cltin;
inline char gc() {
  if (ih == it) {
    it = (ih = cltin) + fread(cltin, 1, 1048576, stdin);
    if (ih == it) return EOF;
  }
  return *ih++;
}
char cltout[1048576 + 1], *oh = cltout, *ot = cltout + 1048576;
inline void pc(char c) {
  if (oh == ot) {
    fwrite(cltout, 1, 1048576, stdout);
    oh = cltout;
  }
  *oh++ = c;
}
template <typename _tp>
inline void read(_tp& x) {
  int sn = 1;
  char c = gc();
  for (; c != 45 && (c < 48 || c > 57) && c != EOF; c = gc())
    ;
  if (c == 45) sn = -1, c = gc();
  for (x = 0; c >= 48 && c <= 57 && c != EOF;
       x = (x << 3) + (x << 1) + (c ^ 48), c = gc())
    ;
  x *= sn;
}
template <typename _tp>
inline void write(_tp x, char text = -1) {
  if (x < 0) pc(45), x = -x;
  if (!x)
    pc(48);
  else {
    int digit[22];
    for (digit[0] = 0; x; digit[++digit[0]] = x % 10, x /= 10)
      ;
    for (; digit[0]; pc(digit[digit[0]--] ^ 48))
      ;
  }
  if (text >= 0) pc(text);
}
}  // namespace cltstream
int n, m, sq;
int p[100000 + 1], r[100000 + 1];
int f[100000 + 1];
inline void work(register int x) {
  f[x] = x;
  for (register int i = 1; i <= sq; ++i) f[x] = p[f[x]];
  for (register int i = 1, u = r[x]; i <= sq && u != x; ++i, u = r[u])
    f[u] = r[f[p[u]]];
}
int main() {
  cltstream::read(n);
  cltstream::read(m);
  sq = sqrt(n);
  for (register int i = 1; i <= n; ++i) {
    cltstream::read(p[i]);
    r[p[i]] = i;
  }
  for (register int i = 1; i <= n; ++i) {
    f[i] = i;
    for (register int j = 1; j <= sq; ++j) f[i] = p[f[i]];
  }
  for (; m; --m) {
    int t, x, y, k;
    int res;
    cltstream::read(t);
    if (t == 1) {
      cltstream::read(x);
      cltstream::read(y);
      std::swap(p[x], p[y]);
      std::swap(r[p[x]], r[p[y]]);
      work(x);
      work(y);
    } else {
      cltstream::read(x);
      cltstream::read(k);
      res = x;
      for (register int i = 1; i <= k / sq; ++i) res = f[res];
      for (register int i = 1; i <= k % sq; ++i) res = p[res];
      cltstream::write(res, 10);
    }
  }
  fwrite(cltstream::cltout, 1, cltstream::oh - cltstream::cltout, stdout),
      cltstream::oh = cltstream::cltout;
  return 0;
}
