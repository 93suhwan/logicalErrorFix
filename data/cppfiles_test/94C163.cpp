#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int T;
long long n, k;
long long cost[20], b[20], a[20];
int main() {
  scanf("%d", &T);
  b[0] = 1;
  for (int i = 1; i <= 10; ++i) {
    b[i] = b[i - 1] * 10;
  }
  while (T--) {
    scanf("%lld%lld", &n, &k);
    k++;
    memset(cost, 0, sizeof(cost));
    memset(a, 0, sizeof(a));
    cost[0] = 1;
    for (int i = 1; i <= n; ++i) {
      int bits;
      scanf("%d", &bits);
      cost[bits] = 1;
    }
    for (int i = 1; i <= 10; ++i) {
      if (!cost[i]) {
        cost[i] = cost[i - 1] * 10;
      }
    }
    long long ans = 0, tot = 0;
    for (int i = 0; i <= 9; ++i) {
      k -= 9 * cost[i];
      a[i] = 9;
      ans += 9 * b[i];
      if (k <= 0) break;
    }
    if (k > 0) {
      ans += (k / cost[10]) * b[10];
      a[10] += (k / cost[10]);
      if (k % cost[10]) {
        ans += b[10];
        a[10]++;
      }
      k -= cost[10] * a[10];
    }
    for (int i = 10; i >= 0; --i) {
      while (a[i] != 0 && (-k) >= cost[i]) {
        ans -= b[i];
        a[i]--;
        k += cost[i];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
