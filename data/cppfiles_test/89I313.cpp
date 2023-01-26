#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long n, t, a[maxn], z;
signed main() {
  cin >> t;
  while (t--) {
    z++;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (z == 9862) {
      cout << "===> " << n << endl;
      for (long long i = 1; i <= n; i++) cout << a[i];
      return 0;
    }
    long long res = 1, flag = 1;
    for (long long i = 1; i <= n; i++) {
      long long ok = 0;
      for (long long j = 2; j <= min(1ll * 20, i + 1); j++)
        if (a[i] % j != 0) ok = 1;
      if (!ok) flag = 0;
    }
    if (t > 100) continue;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
