#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n;
int a[N];
long long f[N][450];
long long sum[N];
inline void Solve() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
  reverse(a + 1, a + 1 + n);
  for (register int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  int lim = sqrt(n + n) + 1;
  for (register int i = 0; i <= n; ++i)
    for (register int j = 0; j <= lim; ++j) f[i][j] = 0;
  f[0][0] = 1e18;
  for (register int i = 1; i <= n; ++i) {
    for (register int j = 1; j <= min(i, lim); ++j) {
      f[i][j] = f[i - 1][j];
      if (f[i - j][j - 1] > sum[i] - sum[i - j])
        f[i][j] = max(f[i - 1][j], sum[i] - sum[i - j]);
    }
  }
  for (register int i = lim; i >= 1; --i)
    if (f[n][i]) {
      printf("%d\n", i);
      return;
    }
}
int main() {
  scanf("%d", &T);
  while (T--) Solve();
  return 0;
}
