#include <bits/stdc++.h>
using namespace std;
namespace red {
inline long long read() {
  long long x = 0;
  char f = 0, ch;
  for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') f = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
const long long N = 1e5 + 10;
long long T, n;
long long a[N], c[N], pos[N], num;
struct node {
  long long l, r, d;
} e[N];
long long tot;
inline void main() {
  T = read();
  while (T--) {
    n = read();
    num = tot = 0;
    for (long long i = 1; i <= n; ++i) a[i] = read(), c[++num] = a[i];
    sort(c + 1, c + num + 1);
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 1; j <= n; ++j) {
        if (a[i] == c[j]) {
          a[i] = j;
          c[j] = 1e9 + 10;
        }
      }
    }
    for (long long pos, i = 1; i <= n; ++i) {
      pos = i;
      for (long long j = i; j <= n; ++j) {
        if (a[j] == i) {
          pos = j;
          break;
        }
      }
      if (pos == i) continue;
      e[++tot].l = i, e[tot].r = pos, e[tot].d = pos - i;
      long long x = a[pos];
      for (long long j = i + 1; j <= pos; ++j) a[j] = a[j - 1];
      a[i] = x;
    }
    printf("%lld\n", tot);
    for (long long i = 1; i <= tot; ++i) {
      printf("%lld %lld %lld\n", e[i].l, e[i].r, e[i].d);
    }
  }
}
}  // namespace red
signed main() {
  red::main();
  return 0;
}
