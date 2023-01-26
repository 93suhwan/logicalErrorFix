#include <bits/stdc++.h>
using namespace std;
const int N = 10007;
long long a[N], sum[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    long long x, y;
    if (i == n) {
      printf("and %d %d\n", i, i + 1);
      fflush(stdout);
      scanf("%lld", &x);
      printf("or %d %d\n", i, i + 1);
      fflush(stdout);
      scanf("%lld", &y);
      sum[i] = x + y;
    } else {
      printf("and %d %d\n", i, i + 1);
      fflush(stdout);
      scanf("%lld", &x);
      printf("or %d %d\n", i, i + 1);
      fflush(stdout);
      scanf("%lld", &y);
      sum[i] = x + y;
    }
  }
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    long long f = 1;
    for (int j = i; j <= n + i - 1; j++) {
      ans += f * sum[(j - 1) % n + 1];
      f = -f;
    }
    a[i] = ans / 2;
  }
  sort(a + 1, a + 1 + n);
  printf("finish %lld\n", a[k]);
  return 0;
}
