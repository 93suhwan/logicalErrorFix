#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0, res, res1, mn;
int a[1002];
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
  return;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 2; i <= n; i += 2) {
    res = mn = 0;
    for (int j = i - 1; j < n; j += 2) {
      ans += max(min(a[i - 1] + min(res, 0LL), a[j + 1] - max(res, 0LL)), 0LL);
      res -= a[j + 1], mn = min(mn, res);
      if (a[i - 1] + mn < 0) break;
      res += a[j + 2];
    }
  }
  return 0 & printf("%lld", ans);
}
