#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
inline void write(register int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
int n, m, K, r, c;
int power(int a, long long b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % 1000000007;
    a = 1ll * a * a % 1000000007, b >>= 1;
  }
  return res;
}
int main() {
  n = read(), m = read(), K = read(), r = read(), c = read();
  int i = read(), j = read(), k = read(), l = read();
  if (i == k && j == l)
    printf("%d\n", power(K, 1ll * n * m));
  else
    printf("%d\n", power(K, 1ll * n * m - 1ll * r * c));
  return 0;
}
