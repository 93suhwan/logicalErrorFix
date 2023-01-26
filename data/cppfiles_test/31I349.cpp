#include <bits/stdc++.h>
using namespace std;
int a[2000009];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int x = a[1];
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
      sum += a[i];
    }
    if (sum != 0) {
      printf("%lld ", sum);
      if (sum > 0) {
        for (int i = 2; i <= n; i++) printf("%d ", -x);
      } else {
        for (int i = 2; i <= n; i++) printf("%d ", x);
      }
      printf("\n");
    } else {
      int x = a[n];
      long long sum = 0;
      for (int i = 1; i <= n - 1; i++) sum += a[i];
      if (sum > 0) {
        for (int i = 1; i <= n - 1; i++) printf("%d ", -x);
      } else {
        for (int i = 1; i <= n - 1; i++) printf("%d ", x);
      }
      printf("%lld\n", sum);
    }
  }
  return 0;
}
