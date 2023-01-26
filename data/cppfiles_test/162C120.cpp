#include <bits/stdc++.h>
using namespace std;
int t, n;
long long h[200200], a[200200];
long long ex[200200];
bool ok(long long sz) {
  for (int i = 0; i < n; i++) {
    a[i] = h[i];
    ex[i] = 0;
  }
  for (int i = n - 1; i > 1; i--) {
    if (a[i] + ex[i] < sz) return 0;
    long long cg = min(a[i], (a[i] + ex[i] - sz)) / 3;
    a[i] -= cg * 3;
    ex[i - 2] += cg * 2;
    ex[i - 1] += cg;
  }
  for (int i = 0; i < n; i++)
    if (a[i] + ex[i] < sz) return 0;
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
