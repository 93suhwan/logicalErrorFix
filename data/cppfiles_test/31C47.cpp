#include <bits/stdc++.h>
using namespace std;
inline void rd(char *x) { scanf("%s", x); }
inline void rd(double &x) { scanf("%lf", &x); }
template <typename T>
inline void rd(T &x) {
  x = 0;
  bool is = 0;
  char ch = getchar();
  while (!isdigit(ch)) is |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  is && (x = -x);
}
template <typename T, typename... U>
inline void rd(T &x, U &...y) {
  rd(x), rd(y...);
}
template <typename T>
inline void write(T x) {
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
const int maxn = 114514;
long long n, a[maxn], b[maxn];
long long sgn(long long x) { return x < 0 ? -1 : 1; }
int main() {
  srand(time(0));
  int T;
  rd(T);
  for (int kase = (1), __kase = (T); kase <= __kase; ++kase) {
    rd(n);
    for (int i = (1), __i = (n); i <= __i; ++i) rd(a[i]);
    if (n % 2 == 0) {
      for (int i = (1), __i = (n / 2); i <= __i; ++i) {
        printf("%lld %lld ", a[i * 2], -a[i * 2 - 1]);
      }
      printf("\n");
      continue;
    }
    long long s2 = 0;
    for (int i = (1), __i = (3); i <= __i; ++i) s2 += a[i];
    b[1] = a[2] + a[3], b[2] = b[3] = -a[1];
    for (int i = (1), __i = (3); i <= __i; ++i) {
      if (s2 - a[i] == 0) continue;
      if ((b[1] == 0 || b[2] == 0 || b[3] == 0) ||
          abs(s2 - 3ll * a[i]) <= abs(b[1] + b[2] + b[3])) {
        b[i] = 0;
        for (int j = (1), __j = (3); j <= __j; ++j)
          if (i != j) b[i] += a[j], b[j] = -a[i];
      }
    }
    if (b[1] == 0 || b[2] == 0 || b[3] == 0)
      while (1)
        ;
    for (int i = (4), __i = (n); i <= __i; ++i) {
      if (i % 2 == 0) {
        b[i] = -a[i + 1], b[i + 1] = a[i];
        if (rand() % 2) b[i] = -b[i], b[i + 1] = -b[i + 1];
      }
    }
    for (int i = (1), __i = (n); i <= __i; ++i) printf("%lld ", b[i]);
    printf("\n");
  }
}
