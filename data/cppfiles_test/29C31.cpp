#include <bits/stdc++.h>
using namespace std;
long long a[66];
int n;
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long sum = 0, x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      sum += a[i];
      if (!a[i]) x++;
      if (a[i] == 1) y++;
    }
    long long ans = y * qmi(2, x);
    printf("%lld\n", ans);
  }
  return 0;
}
