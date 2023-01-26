#include <bits/stdc++.h>
using namespace std;
long long a[200010], c[200010];
long long x, y, l, r, T, n, mm, m, s, s1, s2, ty, tot;
void qs(long long l, long long r) {
  long long i = l, j = r;
  long long x = a[(l + r) >> 1];
  do {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (i < r) qs(i, r);
  if (l < j) qs(l, j);
}
int main() {
  cin >> n;
  tot = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    tot += a[i];
  }
  a[0] = 0;
  qs(1, n);
  cin >> mm;
  for (long long i = 1; i <= mm; i++) {
    scanf("%lld%lld", &x, &y);
    l = 0;
    r = n;
    s = 0;
    if (a[r] < x) {
      s = x - a[r];
      ty = tot - a[r];
      s += max(y - ty, (long long)0);
      c[i] = s;
      continue;
    }
    while (l + 1 < r) {
      m = (l + r) >> 1;
      if (a[m] >= x)
        r = m;
      else
        l = m;
    }
    ty = tot - a[r];
    s1 = max(y - ty, (long long)0);
    s2 = x - a[l];
    ty = tot - a[l];
    s2 += max(y - ty, (long long)0);
    s = min(s1, s2);
    c[i] = s;
  }
  for (long long i = 1; i <= mm; i++) printf("%lld\n", c[i]);
  return 0;
}
