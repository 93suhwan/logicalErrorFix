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
int test(int id, int v) {
  putchar('?');
  for (int i = (1); i <= (n); ++i)
    if (i == id)
      printf(" 1");
    else
      printf(" %d", v);
  putchar('\n');
  fflush(stdout);
  return readint();
}
int main() {
  n = readint();
  int best = 0;
  for (int i = (1); i <= (n); ++i) {
    int pos = test(i, n);
    if (pos != 0) {
      a[pos] = 1;
      best = i;
      break;
    }
  }
  for (int i = 2; i < n; ++i) a[test(best, n + 1 - i)] = i;
  a[best] = n;
  putchar('!');
  for (int i = (1); i <= (n); ++i) printf(" %d", a[i]);
  putchar('\n');
  fflush(stdout);
  return 0;
}
