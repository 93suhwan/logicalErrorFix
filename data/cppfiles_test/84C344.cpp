#include <bits/stdc++.h>
long long t, n, s;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &s);
    long long p = n - (n + 1) / 2 + 1;
    printf("%lld\n", s / p);
  }
  return 0;
}
