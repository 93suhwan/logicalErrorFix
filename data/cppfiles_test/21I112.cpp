#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
long long x[200005], y[200005], a[200005], ans;
int s[200005], To[200005], n;
int fi(long long tx) {
  int l = 0, r = n, t = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (x[mid] > tx)
      t = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return t;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld%d", &x[i], &y[i], &s[i]);
  x[n + 1] = x[n] + 1;
  for (int i = 1; i <= n; i++) To[i] = fi(y[i]);
  a[0] = x[1];
  for (int i = 1; i <= n; i++)
    a[i] = (a[i - 1] + x[To[i]] - y[i] + a[i - 1] - a[To[i] - 1] + x[i + 1] -
            x[i]) %
           p;
  ans = x[1];
  for (int i = 1; i <= n; i++)
    if (s[i])
      ans = (ans + a[i] - a[i - 1]) % p;
    else
      ans = (ans + x[i + 1] - x[i]) % p;
  printf("%lld\n", ans);
  return 0;
}
