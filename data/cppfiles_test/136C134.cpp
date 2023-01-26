#include <bits/stdc++.h>
const int N = 1e5 + 10;
long long a[N], b[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, res = 0, k = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      k += a[i];
    }
    k *= 2;
    if (k % (n * (n + 1)) != 0) {
      printf("NO\n");
      continue;
    }
    k /= n * (n + 1);
    int L = n - 1;
    for (int i = 0; i < n; i++) {
      long long num = a[i] - k;
      if (num <= 0) {
        k = -1;
        break;
      }
      num = a[L % n] - num;
      if (num <= 0 || num % n != 0) {
        k = -1;
        break;
      }
      b[i] = num / n;
      L++;
    }
    if (n == 1) {
      b[0] = a[0];
      k = 0;
    }
    if (k == -1)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 0; i < n; i++) printf("%d ", b[i]);
      printf("\n");
    }
  }
  return 0;
}
