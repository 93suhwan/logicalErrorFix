#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    if (2 * m > n * (n - 1))
      printf("NO\n");
    else if (m == 0 && n == 1) {
      if (k >= 2)
        printf("YES\n");
      else
        printf("NO\n");
    } else if (2 * m == n * (n - 1)) {
      if (k >= 3)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      if (m >= n - 1) {
        if (k > 3)
          printf("YES\n");
        else
          printf("NO\n");
      } else
        printf("NO\n");
    }
  }
  return 0;
}
