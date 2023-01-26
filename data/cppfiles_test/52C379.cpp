#include <bits/stdc++.h>
using namespace std;
int t, n;
long long maxx, sum, a;
int main() {
  scanf("%d", &t);
  while (t--) {
    sum = 0, maxx = -9999999999;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a);
      sum += a;
      maxx = max(maxx, a);
    }
    double ans = maxx + (double)(sum - maxx) / (double)(n - 1);
    printf("%lf\n", ans);
  }
  return 0;
}
