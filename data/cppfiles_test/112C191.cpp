#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int rd() {
  int x = 0, fl = 1;
  char ch = getchar();
  for (; ch < 48 || ch > 57; ch = getchar())
    if (ch == '-') fl = -1;
  for (; 48 <= ch && ch <= 57; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * fl;
}
const int N = 1000002, M = 998244353;
int pw(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % M)
    if (y & 1) z = 1ll * z * x % M;
  return z;
}
int T, a, b, c, m;
signed main() {
  scanf("%d", &T);
  for (; T--;) {
    scanf("%d%d%d%d", &a, &b, &c, &m);
    if (c > a) swap(a, c);
    if (b > a) swap(a, b);
    if (c > b) swap(b, c);
    if (m > a - 1 + b - 1 + c - 1) {
      puts("NO");
      continue;
    }
    if (a > b + c) {
      if (m < a - 1 - b - c) {
        puts("NO");
        continue;
      }
    }
    puts("YES");
  }
}
