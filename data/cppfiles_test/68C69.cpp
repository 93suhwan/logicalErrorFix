#include <bits/stdc++.h>
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n, c, r;
    scanf("%lld", &n);
    long long l = ceil(sqrt(n));
    long long d = l * l - n;
    long long k = d - l;
    if (d < l) {
      r = l;
      c = d + 1;
    }
    if (d >= l) {
      r = l - k - 1;
      c = l;
    }
    printf("%lld %lld\n", r, c);
  }
  return 0;
}
