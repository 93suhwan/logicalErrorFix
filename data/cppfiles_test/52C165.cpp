#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[200000];
  int t, n, k;
  cin >> n;
  while (n--) {
    cin >> t;
    double ans = 0;
    long long sum = 0;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= t; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    sort(a + 1, a + t + 1);
    ans += a[t];
    sum -= a[t];
    ans = ans + (double)(double)sum / (double)(t - 1);
    printf("%lf\n", ans);
  }
}
