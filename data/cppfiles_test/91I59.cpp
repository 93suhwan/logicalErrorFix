#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
const long long mod = 998244353;
int a[mx];
long long sum[mx];
void oyl(int n) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = (sum[i - 1] + i * a[i] - i) % mod;
  }
  for (int i = 1, x, y; i <= n; i++) {
    x = a[i];
    for (int j = i - 1; j >= 1; --j) {
      if (x == 1) {
        ans += sum[j];
        break;
      }
      if (a[j] <= x)
        x = a[j];
      else {
        y = (x + a[j] - 1) / x;
        ans += j * (y - 1);
        x = a[j] / y;
      }
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    oyl(n);
  }
}
