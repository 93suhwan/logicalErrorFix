#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n == 1 && m == 0 && k > 1)
      printf("YES\n");
    else if (m == (n - 1) * n / 2) {
      if (k > 2)
        printf("YES\n");
      else
        printf("NO\n");
    } else if (m >= n - 1 && m < (n - 1) * n / 2) {
      if (k > 3)
        printf("YES\n");
      else
        printf("NO\n");
    } else
      printf("NO\n");
  }
  return 0;
}
