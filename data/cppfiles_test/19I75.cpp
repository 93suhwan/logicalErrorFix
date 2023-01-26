#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long inf = 4557430888798830399;
template <typename _tp>
inline void read(_tp& x) {
  char ch = getchar(), sgn = 0;
  while (ch ^ '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') ch = getchar(), sgn = 1;
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (sgn) x = -x;
}
const long long N = 1e4;
const long long M = 3e3;
long long f[N][M];
long long n, a[maxn];
long long mx;
signed main() {
  long long T;
  read(T);
  while (T--) {
    read(n);
    for (long long i = 1; i <= n; ++i) read(a[i]);
    mx = a[max_element(a + 1, a + 1 + n) - a];
    for (long long i = 0; i <= n; ++i) {
      for (long long j = 0; j <= 2 * mx + 1; ++j) f[i][j] = inf;
    }
    f[0][0] = 0;
    for (long long i = 0; i <= n - 1; ++i) {
      for (long long j = 0; j <= 2 * mx + 1; ++j) {
        if (f[i][j] == inf) continue;
        long long len = a[i + 1];
        f[i + 1][max(j - len, 0ll)] =
            min(f[i + 1][max(j - len, 0ll)], f[i][j] + len);
        f[i + 1][j + len] = min(f[i + 1][j + len], max(0ll, f[i][j] - len));
      }
    }
    long long ans = 2 * mx + 1;
    for (long long i = 0; i <= 2 * mx + 1; ++i) {
      ans = min(ans, i + f[n][i]);
    }
    cout << ans << endl;
  }
  return 0;
}
