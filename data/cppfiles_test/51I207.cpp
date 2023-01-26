#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    long long int n;
    scanf("%lld", &n);
    long long int ans = -1 * (n - 1);
    printf("%lld %lld", ans, n);
  }
}
