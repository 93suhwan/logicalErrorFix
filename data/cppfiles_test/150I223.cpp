#include <bits/stdc++.h>
const int N = 5e5 + 10;
const int M = 9699690;
const int mod = 998244353, Gi = 332748118;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
using std::pair;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
int random(int i) { return rand() % i + 1; }
template <class T>
void ckmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void ckmin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
inline int plus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qp(int d, int k) {
  int f = 1;
  while (k) {
    if (k & 1) f = (1ll * (f) * (d) % mod);
    d = (1ll * (d) * (d) % mod), k >>= 1;
  }
  return f;
}
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int n, a[200];
void work() {
  read(n);
  int f0 = 0, f1 = 0, f2 = 0, mx = 0;
  for (int i = (1); i <= (n); i++) {
    read(a[i]);
    ckmax(mx, a[i]);
    f0 |= a[i] % 3 == 0;
    f1 |= a[i] % 3 == 1;
    f2 |= a[i] % 3 == 2;
  }
  if (mx % 3 == 2) {
    if (f1)
      printf("%d\n", mx / 3 + 2);
    else
      printf("%d\n", mx / 3 + 1);
  }
  if (mx % 3 == 1) {
    if (f0 && f2)
      printf("%d\n", mx / 3 + 2);
    else
      printf("%d\n", mx / 3 + 1);
  }
  if (mx % 3 == 0) {
    if (f1 || f2)
      printf("%d\n", mx / 3 + 1);
    else
      printf("%d\n", mx / 3);
  }
}
int main() {
  int T = 1;
  read(T);
  while (T--) work();
  return 0;
}
