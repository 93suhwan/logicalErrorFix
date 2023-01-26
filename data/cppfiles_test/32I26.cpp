#include <bits/stdc++.h>
using namespace std;
int a[1001][320], f[1001][320], n, t, ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i][1]);
    for (int k = 2; k <= sqrt(n) + 1; k++)
      for (int i = k; i <= n; i++) a[i][k] = a[i - 1][k - 1] + a[i][1];
    f[n][1] = a[n][1];
    for (int i = n - 1; i >= 1; i--) {
      f[i][1] = a[i][1];
      for (int k = 1; k <= sqrt(n) + 1 && i - k >= 0; k++) {
        if (f[i + 1][k] && a[i][k + 1] < f[i + 1][k] && a[i][k + 1]) {
          f[i - k + 1][k + 1] = max(f[i - k + 1][k + 1], a[i][k + 1]);
          ans = max(ans, k + 1);
        }
        f[i][k] = max(f[i][k], f[i + 1][k]);
      }
    }
    cout << ans << endl;
  }
}
