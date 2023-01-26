#include <bits/stdc++.h>
using namespace std;
static char ibuf[1 << 20];
char *fis = ibuf, *fit = ibuf;
inline char readChar() {
  return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin),
                        fis == fit)
             ? EOF
             : *fis++;
}
inline int read() {
  char c, _c;
  int x;
  for (c = readChar(); !isdigit(c); c = readChar())
    ;
  for (x = 0; isdigit(c); c = readChar()) {
    x = x * 10 + c - '0';
  }
  return x;
}
static char ostc[100], obuf[1 << 20];
int ol = 0;
char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) {
  *fos++ = c;
  if (fos == fot) {
    fwrite(obuf, 1, fos - obuf, stdout);
    fos = obuf;
  }
}
inline void write(int n, char c) {
  if (!n) {
    writeChar('0');
  } else {
    while (n) {
      ostc[++ol] = n % 10 + 48, n /= 10;
    }
  }
  for (; ol; ol--) {
    writeChar(ostc[ol]);
  }
  writeChar(c);
}
const int mod = 1e9 + 7;
int qpow(int x, long long times) {
  int res = 1;
  while (times) {
    if (times & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    times >>= 1;
  }
  return res;
}
int main() {
  int n, m, k, r, c;
  int ax, ay, bx, by;
  scanf("%d%d%d%d%d", &n, &m, &k, &r, &c);
  scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  if (ax == bx && ay == by)
    printf("%d\n", qpow(k, 1LL * n * m));
  else
    printf("%d\n", qpow(k, 1LL * n * m - 1LL * r * c));
}
