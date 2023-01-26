#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0, c = getchar(), f = 1;
  for (; '0' > c || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
void writeUnsigned(const unsigned &x) {
  if (x > 9) writeUnsigned(x / 10);
  putchar((x - x / 10 * 10) ^ 48);
}
inline void writeint(const int &x) {
  if (x < 0) {
    putchar('-');
    writeUnsigned(-x);
  } else
    writeUnsigned(x);
}
const int MAXN = 105;
int n, a[MAXN];
int test(int id, int me, int v) {
  putchar('?');
  for (int i = (1); i <= (n); ++i)
    if (i == id)
      printf(" %d", me);
    else
      printf(" %d", v);
  putchar('\n');
  fflush(stdout);
  return readint();
}
int main() {
  n = readint();
  if (test(n, 2, 1)) {
    a[n] = 1;
    for (int v = n - 1; v >= 2; --v)
      if (test(n, n, v)) {
        a[n] = v;
        break;
      }
  } else
    a[n] = n;
  for (int i = 1; i <= n; ++i)
    if (i != a[n]) {
      int pos = test(n, n + 1 - a[n], n + 1 - i);
      a[pos] = i;
    }
  putchar('!');
  for (int i = (1); i <= (n); ++i) printf(" %d", a[i]);
  putchar('\n');
  fflush(stdout);
  return 0;
}
