#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  long long t, rr, i, k, l, z;
  scanf("%lld", &t);
  for (rr = 0; rr < t; rr++) {
    scanf("%lld%lld", &n, &m);
    z = 0;
    m++;
    for (i = 29; i >= 0; i--) {
      k = n >> i & 1;
      l = m >> i & 1;
      if (k && !l) {
        goto X;
      }
      if (!k && l) {
        z |= 1ll << i;
      }
    }
  X:
    printf("%lld\n", z);
  }
}
