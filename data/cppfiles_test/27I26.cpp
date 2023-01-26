#include <bits/stdc++.h>
int t;
long long n, m, k;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (k - 2 <= 0 || n - 1 > m || m > (n * (n - 1) >> 1ll))
      puts("NO");
    else if (m != (n * (n - 1ll) >> 1ll) && k == 3)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
