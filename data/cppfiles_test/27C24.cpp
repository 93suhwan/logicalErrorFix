#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    if (k <= 1) {
      printf("NO\n");
      continue;
    }
    if (k == 2) {
      if (n == 1 && m == 0)
        printf("YES\n");
      else
        printf("NO\n");
      continue;
    }
    long long x = (n - 1) * n / 2;
    if (k == 3) {
      if (m == x)
        printf("YES\n");
      else
        printf("NO\n");
      continue;
    }
    if (k > 3) {
      if (m >= n - 1 && m <= x)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
