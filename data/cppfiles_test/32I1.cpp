#include <bits/stdc++.h>
using namespace std;
long long a[100001], f[100001][620], n, t, ans;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    ans = 1;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
    for (long long i = n - 1; i >= 1; i--) {
      f[i][1] = a[i];
      for (long long k = 1; k <= sqrt(n * 2) && i - k >= 1; k++) {
        if (f[i + 1][k]) {
          f[i - k][k + 1] = max(f[i - k][k + 1], a[i] - a[i - k - 1]);
          ans = max(ans, k + 1);
        }
        f[i][k] = max(f[i][k], f[i + 1][k]);
      }
    }
    cout << ans << endl;
    for (long long k = 0; k <= sqrt(n * 2); k++)
      for (long long i = k; i <= n; i++) f[i][k] = 0;
    memset(a, 0, sizeof(a));
  }
}
