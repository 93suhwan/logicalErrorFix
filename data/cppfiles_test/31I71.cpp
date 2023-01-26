#include <bits/stdc++.h>
using namespace std;
int t, n, b[100010], lcm, a[100010], ans[100010];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      a[i] = abs(b[i]);
    }
    lcm = a[1] * a[2] / gcd(a[1], a[2]);
    for (int i = 3; i <= n; ++i) lcm = lcm * a[i] / gcd(lcm, a[i]);
    if (n & 1) {
      for (int i = 1; i <= n - 3; i += 2) {
        ans[i] = -(lcm / b[i]);
        ans[i + 1] = lcm / b[i + 1];
      }
      ans[n] = -2 * (lcm / b[n]);
      ans[n - 1] = lcm / b[n - 1];
      ans[n - 2] = lcm / b[n - 2];
    } else
      for (int i = 1; i <= n; i += 2) {
        ans[i] = -(lcm / b[i]);
        ans[i + 1] = lcm / b[i + 1];
      }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
