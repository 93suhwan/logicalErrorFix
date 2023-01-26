#include <bits/stdc++.h>
using namespace std;
double check(int n, int k) {
  double ans = 0, now = 1, i, j;
  n -= k;
  for (i = 1; i <= 3; i++) {
    if (i > k || 3 - i > n) continue;
    now = 1;
    for (j = k; j > k - i; j--) now *= j;
    for (j = n; j > n - (3 - i); j--) now *= j;
    for (j = 1; j <= i; j++) now /= j;
    for (j = 1; j <= 3 - i; j++) now /= j;
    ans += now / 2;
    if (i != 1) ans += now / 2;
  }
  ans *= 6;
  n += k;
  ans /= n;
  ans /= n - 1;
  ans /= n - 2;
  return ans;
}
int main() {
  int n, l, r, ans;
  double p;
  scanf("%d%lf", &n, &p);
  l = 0;
  r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(n, mid) >= p)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
