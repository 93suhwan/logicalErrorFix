#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll s, n, k;
    scanf("%lld %lld %lld", &s, &n, &k);
    if (s == n)
      puts("YES");
    else
      puts(s / (2 * k) * k + min(s % (2 * k), k - 1) < n ? "YES" : "NO");
  }
  return 0;
}
