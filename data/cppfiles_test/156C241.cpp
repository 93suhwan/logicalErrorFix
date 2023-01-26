#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int i, n, t;
int a[maxn];
long long k, res;
long long s[maxn];
long long divide(long long a, long long b) {
  if (a >= 0) return a / b;
  if (a % b == 0) return a / b;
  long long res = (-a) / b;
  return -res - 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%lld", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (i = 2; i <= n; i++) s[i] = s[i - 1] + a[i];
    res = 1e15;
    for (i = 1; i <= n; i++) {
      long long goal = divide(k - s[i], n + 1ll - i);
      res = min(res, max(0ll, a[1] - goal) + n - i);
    }
    printf("%lld\n", res);
  }
  return 0;
}
