#include <bits/stdc++.h>
using namespace std;
int t, n;
long long h[200200], a[200200];
bool ok(long long sz) {
  for (int i = 0; i < n; i++) a[i] = h[i];
  for (int i = 2; i < n; i++) {
    if (a[i - 2] >= sz && a[i - 1] >= sz) continue;
    long long req = max(sz - a[i - 1], (sz - a[i - 2] + 1) / 2);
    req = min(req, a[i] / 3);
    a[i] -= req * 3;
    a[i - 1] += req;
    a[i - 2] += req * 2;
  }
  for (int i = 0; i < n; i++)
    if (a[i] < sz) return 0;
  return 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
    long long lo = 1, hi = 2000000000;
    while (lo != hi) {
      long long avg = (lo + hi + 1) / 2;
      if (ok(avg))
        lo = avg;
      else
        hi = avg - 1;
    }
    printf("%lld\n", lo);
  }
}
