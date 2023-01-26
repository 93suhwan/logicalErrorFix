#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        printf("YES\n");
      else
        printf("NO\n");
    } else if (n & 1) {
      int x = k - m / 2;
      if (x >= 0 && x % 2 == 0)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      if (k <= n * (m - 1) / 2 && k % 2 == 0)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
