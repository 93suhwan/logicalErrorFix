#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30, N = 17, M = 44000;
int n, m, t, tot = 1;
int a[200005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    double b = 2.0 * sum / n;
    long long c = b;
    if (b - c >= 0.0000001) {
      printf("0\n");
      continue;
    }
    long long ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      if (a[i] > (b / 2) + 0.00001) break;
      int p = lower_bound(a + 1, a + 1 + n, c - a[i]) - a;
      p = max(i + 1, p);
      int op = upper_bound(a + 1, a + 1 + n, c - a[i]) - a;
      op = max(i + 1, op);
      ans += (op - p);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
