#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, mod = 998244353;
int f[N][2], a[N], t, n, ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) f[i][0] = f[i][1] = 0;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = f[a[i]][0] + (a[i] == 1), y = f[a[i]][1] + (a[i] == 0);
      if (a[i] - 2 >= 0) (x += f[a[i] - 2][1]) %= mod;
      if (a[i] - 1 >= 0) (y += f[a[i] - 1][1]) %= mod;
      ans = ((x + y) % mod + ans) % mod;
      (f[a[i]][0] += x) %= mod, (f[a[i]][1] += y) %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
