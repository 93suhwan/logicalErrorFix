#include <bits/stdc++.h>
using namespace std;
long long T, s, n, k;
signed main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (n < k) {
      if (s == k)
        puts("YES");
      else
        puts("NO");
      continue;
    }
    long long w = n / k * 2ll * k + n % k;
    if (s < w)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
