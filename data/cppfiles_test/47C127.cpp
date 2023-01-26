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
int T, n, k;
long long ans;
int a[200000 + 1], b[200000 + 1];
int main() {
  cltstream::read(T);
  for (; T; --T) {
    cltstream::read(n);
    cltstream::read(k);
    a[0] = b[0] = 0;
    for (register int i = 1; i <= n; ++i) {
      int x;
      cltstream::read(x);
      if (x > 0) a[++a[0]] = x;
      if (x < 0) b[++b[0]] = -x;
    }
    std::sort(a + 1, a + a[0] + 1);
    std::sort(b + 1, b + b[0] + 1);
    ans = 0;
    for (register int i = a[0]; i >= 1; i -= k) ans += 2 * a[i];
    for (register int i = b[0]; i >= 1; i -= k) ans += 2 * b[i];
    ans -= std::max(a[a[0]], b[b[0]]);
    cltstream::write(ans, 10);
  }
  fwrite(cltstream::cltout, 1, cltstream::oh - cltstream::cltout, stdout),
      cltstream::oh = cltstream::cltout;
  return 0;
}
