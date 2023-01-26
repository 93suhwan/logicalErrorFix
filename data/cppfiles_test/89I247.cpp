#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long n, t, a[maxn];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long res = 1, flag = 1;
    for (long long i = 1; i <= n; i++) {
      if (res <= 1e9) res *= (i + 1);
      if (a[i] % res == 0) flag = 0;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
