#include <bits/stdc++.h>
using namespace std;
long long p[1000005], q[1000005];
int main() {
  long long t, n, m, i, j, k;
  cin >> t;
  while (t--) {
    long long mx = 0, ok1 = 0, ok2 = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &p[i]);
      mx = max(mx, p[i]);
      if (p[i] % 3 == 1) ok1 = 1;
      if (p[i] % 3 == 2) ok2 = 1;
    }
    long long ans = mx / 3;
    if (ok1) ans++;
    if (ok2) ans++;
    if (ok1 && ok2 && mx % 3 == 0) ans--;
    if (ok2 && mx % 3 == 1) ans--;
    printf("%lld\n", ans);
  }
  return 0;
}
