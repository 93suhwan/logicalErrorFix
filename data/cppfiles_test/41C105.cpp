#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long N = 1010;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long n, K, go, to[N][N], qwq;
signed main() {
  n = read(), K = read();
  long long p = 1;
  for (register long long i = K; i <= 100000000; i *= K) {
    for (register long long j = 1; j <= n; j++)
      for (register long long k = j + 1; k <= n; k++) {
        if ((j - 1) / i == (k - 1) / i && !to[j][k]) {
          to[j][k] = p, qwq++;
        }
      }
    if (qwq == n * (n - 1) / 2) break;
    p++;
  }
  printf("%lld\n", p);
  for (register long long i = 1; i <= n; i++)
    for (register long long j = i + 1; j <= n; j++) printf("%lld ", to[i][j]);
  puts("");
  return 0;
}
