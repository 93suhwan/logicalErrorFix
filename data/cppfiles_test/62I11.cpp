#include <bits/stdc++.h>
long long t, n, k, tol, flag;
long long a[10005];
using namespace std;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    tol = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] == 1) tol++;
    }
    if (a[1] == 1) {
      printf("%lld ", n + 1);
      for (int i = 1; i < n; i++) printf("%lld ", i);
      printf("%lld\n", n);
    } else if (tol == 0) {
      for (int i = 1; i <= n; i++) printf("%lld ", i);
      printf("%lld\n", n + 1);
    } else {
      for (int i = 1; i < n; i++) {
        if (a[i] == 0 and a[i + 1] == 1) {
          k = i;
          break;
        }
      }
      for (int i = 1; i <= k; i++) printf("%lld ", i);
      printf("%lld ", n + 1);
      for (int i = k + 1; i < n; i++) printf("%lld ", i);
      printf("%lld\n", n);
    }
  }
  return 0;
}
