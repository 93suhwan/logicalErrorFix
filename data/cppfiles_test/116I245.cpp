#include <bits/stdc++.h>
int n, t, a[3], b[3], c, ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    a[0] = a[1] = a[2] = 0;
    b[0] = b[1] = b[2] = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c);
      if (c <= 2) {
        ++a[c];
        b[c] += b[c];
        if (b[c] >= 998244353) b[c] -= 998244353;
      }
    }
    printf("%d\n", (b[1] - 1 + (long long)(b[0] - 1) * b[2]) % 998244353);
  }
}
