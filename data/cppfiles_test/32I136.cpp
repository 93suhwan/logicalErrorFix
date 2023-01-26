#include <bits/stdc++.h>
using namespace std;
long long a[100005], f[100005][333];
int T, n, ans;
const long long inf = 1ll << 62;
int main() {
  int i, j;
  cin >> T;
  for (i = 0; i <= 100000; i++) f[i][0] = inf;
  for (; T--;) {
    cin >> n;
    ans = 0;
    for (i = n; i >= 1; i--) scanf("%lld", &a[i]);
    for (i = 1; i <= n; i++) a[i] += a[i - 1];
    for (i = 1; i <= n; i++) {
      for (j = 1; j * (j + 1) <= i * 2; j++) {
        f[i][j] = 0;
        if (f[i - j][j - 1] > a[i] - a[i - j]) f[i][j] = a[i] - a[i - j];
        f[i][j] = max(f[i][j], f[i - 1][j]);
        if (f[i][j] > 0) ans = max(ans, j);
      }
    }
    printf("%d\n", ans);
  }
}
