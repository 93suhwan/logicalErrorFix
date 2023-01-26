#include <bits/stdc++.h>
int t;
long long n, m, k;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (k - 1 <= 0 || n - 1 > m || m > (n * (n - 1ll) >> 1ll))
      puts("NO");
    else if (k == 2)
      puts(n == 1 ? "YES" : "NO");
    else if (k == 3)
      puts(m == (n * (n - 1ll) >> 1ll) ? "YES" : "NO");
    else
      puts("YES");
  }
  return 0;
}
