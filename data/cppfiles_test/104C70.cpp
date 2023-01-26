#include <bits/stdc++.h>
const int N = 200005;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
int n, m;
int a[N], b[N], x[N];
int main() {
  int task;
  for (scanf("%d", &task); task--;) {
    scanf("%d%d", &n, &m);
    long long s = 0, low = 0, high = 0;
    s = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", a + i, b + i);
      s += a[i] - b[i] + m;
      low += max(0, m - b[i]);
      high += min(a[i], m);
    }
    high -= low, s -= low * 2;
    int res = s & 1;
    if (res) {
      if (s < 0)
        ++s;
      else
        --s;
    }
    if (s < 0)
      printf("%lld\n", res - s);
    else if (s <= high * 2)
      printf("%d\n", res);
    else
      printf("%lld\n", res + (s - high * 2));
    for (int i = 0; i < n; ++i) {
      if (s > 0) {
        x[i] = min(s / 2, min(a[i], m) - max(0, m - b[i]));
        s -= x[i] * 2;
      } else
        x[i] = 0;
      x[i] += max(0, m - b[i]);
    }
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", x[i], m - x[i]);
    }
  }
  return 0;
}
