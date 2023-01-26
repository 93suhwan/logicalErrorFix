#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long col = (long long)ceil(log(n) * 1.0 / log(k));
  printf("%lld\n", col);
  for (long long i = 0; i < n; i++)
    for (long long j = i + 1; j < n; j++) {
      long long cs = 0, x = i, y = j;
      while (x != y) x /= k, y /= k, ++cs;
      printf("%lld ", cs);
    }
  return 0;
}
