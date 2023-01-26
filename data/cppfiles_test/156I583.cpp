#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int T, n, A[maxn];
long long k, SUM[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    long long sum = 0, ans = 0;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      sum += 1ll * A[i];
    }
    if (sum <= k) {
      puts("0");
      continue;
    }
    sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++) SUM[i] = SUM[i - 1] + A[i];
    if (n == 1) {
      printf("%d\n", A[1] - k);
      continue;
    }
    for (int i = 1; i <= n; i++) {
      long long s = k - (SUM[i] - SUM[1]);
      if (s > 0)
        s = s / (n - i + 1);
      else
        s = s / (n - i + 1) - (s % (n - i + 1) != 0);
      if (i == 2)
        ans = A[1] - s + (n - i);
      else
        ans = min(ans, A[1] - s + (n - i));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
