#include <bits/stdc++.h>
using namespace std;
long long n, k;
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld", &n, &k);
    long long w = 0, l = 0, b = 1;
    long long ta = 1, tb = 1;
    for (long long i = 1; i < n; i++) {
      ta <<= 1;
      ta %= 1000000007;
      tb <<= 1;
      tb %= 1000000007;
    }
    if (n & 1) {
      ta--;
      if (ta < 0) ta += 1000000007;
      tb--;
      if (tb < 0) tb += 1000000007;
    } else {
      tb -= 2;
      if (tb < 0) tb += 1000000007;
    }
    while (k--) {
      if (n & 1) {
        b = (2 + tb) * b;
        b %= 1000000007;
      } else {
        w += b;
        w %= 1000000007;
        b = (1 + tb) * b;
        b %= 1000000007;
      }
    }
    printf("%lld\n", (w + b) % 1000000007);
  }
  return 0;
}
