#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int t, n, ans;
long long a[200005], st[200005][20], b[200005];
long long ask(int l, int r) {
  int now = l;
  long long tmp = 0;
  for (int j = 19; ~j; --j) {
    if (now > r) break;
    if (now + (1 << j) - 1 <= r) {
      tmp = gcd(st[now][j], tmp);
      now += (1 << j);
    }
  }
  return tmp;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n), ans = 1;
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    if (n == 1) {
      puts("1");
      continue;
    }
    for (int i = 1; i < n; ++i) b[i] = abs(a[i] - a[i + 1]);
    for (int i = 1; i < n; ++i) st[i][0] = b[i];
    for (int k = 1; k <= 19; ++k)
      for (int i = 1; i + (1 << k) - 1 < n; ++i)
        st[i][k] = gcd(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    for (int i = 1; i <= n; ++i) {
      int l = i + 1, r = n, pos = -1;
      while (l <= r) {
        int mid = l + r >> 1;
        if (ask(i, mid - 1) > 1)
          l = mid + 1, pos = mid;
        else
          r = mid - 1;
      }
      if (pos != -1) ans = max(ans, pos - i + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
