#include <bits/stdc++.h>
namespace fastIO {
const int maxc = 1 << 23;
char ibuf[maxc], *__p1 = ibuf, *__p2 = ibuf;
inline char getchar() {
  return __p1 == __p2 && (__p2 = (__p1 = ibuf) + fread(ibuf, 1, maxc, stdin),
                          __p1 == __p2)
             ? EOF
             : *__p1++;
}
template <typename T>
void read(T &n) {
  int x = 0;
  n = 0;
  char c = getchar();
  while (!isdigit(c)) x |= (c == '-'), c = getchar();
  while (isdigit(c)) n = n * 10 + c - '0', c = getchar();
  n = x ? -n : n;
}
void read(char *s) {
  int p = 0;
  char c = getchar();
  while (!isdigit(c) && !isalpha(c)) c = getchar();
  while (isalpha(c) || isdigit(c)) s[p++] = c, c = getchar();
  return;
}
char obuf[maxc], *__pO = obuf;
inline void putchar(char c) { *__pO++ = c; }
template <typename T>
void print(const T &x) {
  if (x < 0)
    putchar('-'), print(-x);
  else {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
  }
  return;
}
template <typename T>
inline void print(const T &x, const char &c) {
  print(x), putchar(c);
}
void output() { fwrite(obuf, __pO - obuf, 1, stdout); }
}  // namespace fastIO
using namespace fastIO;
template <typename T>
inline T max(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T chkmax(T &a, const T &b) {
  return a = max(a, b);
}
template <typename T>
inline T chkmin(T &a, const T &b) {
  return a = min(a, b);
}
template <typename T>
inline T myabs(const T &a) {
  return a >= 0 ? a : -a;
}
template <typename T>
inline void myswap(T &a, T &b) {
  T t = a;
  a = b, b = t;
  return;
}
const int maxn = 2e5 + 5;
int a[maxn], n;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int T;
  read(T);
  while (T--) {
    read(n);
    bool flag = 1;
    for (int i = (1); i <= (n); ++i) read(a[i]), flag &= (a[i] == 0);
    if (flag) {
      for (int i = (1); i <= (n); ++i) print(i, ' ');
      putchar('\n');
      continue;
    }
    int g = 0;
    for (int j = (0); j <= (29); ++j) {
      int cnt = 0;
      for (int i = (1); i <= (n); ++i)
        if (a[i] & (1 << j)) ++cnt;
      g = gcd(cnt, g);
    }
    for (int i = (1); i <= (n); ++i)
      if (g % i == 0) print(i, ' ');
    putchar('\n');
  }
  return output(), 0;
}
