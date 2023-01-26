#include <bits/stdc++.h>
using namespace std;
double a[100005];
int main() {
  int t, n;
  cin >> t;
  double ans, m;
  while (t--) {
    m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    sort(a + 1, a + n + 1);
    ans = a[n];
    for (int i = 1; i < n; i++) m += a[i];
    ans += m / (n - 1);
    printf("%.9lf\n", ans);
  }
  return 0;
}
