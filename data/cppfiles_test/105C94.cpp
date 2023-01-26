#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int T, n, x, a[N], c[N], lst[N], f[N][N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) c[i] = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &x), lst[i] = c[x], c[x] = i;
  for (int r = 1; r <= n; ++r)
    for (int l = r - 1; l >= 1; --l) {
      f[l][r] = f[l][r - 1] + 1;
      for (int i = lst[r]; i >= l; i = lst[i])
        f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r]);
    }
  printf("%d\n", f[1][n]);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
