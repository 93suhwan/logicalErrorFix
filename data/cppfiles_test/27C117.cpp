#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    long long x = n - 1;
    if (n == 1 && m == 0 && k > 1)
      printf("YES\n");
    else if ((m == n * x / 2) && k > 2) {
      printf("YES\n");
    } else if (m >= n - 1 && m < x * n / 2 && k > 3) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
