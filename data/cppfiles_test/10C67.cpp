#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
int n, m, k, r, c;
int ax, ay, bx, by;
long long fpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
bool inter(int x1, int x2, int x3, int x4) {
  if (x1 > x3) {
    std::swap(x1, x3);
    std::swap(x2, x4);
  }
  return x1 <= x3 && x3 <= x2;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &r, &c);
  scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  if (ax == bx && ay == by) {
    printf("%lld\n", fpow(k, (long long)n * m));
    return 0;
  }
  if (!inter(ax, ax + r - 1, bx, bx + r - 1) ||
      !inter(ay, ay + c - 1, by, by + c - 1)) {
    long long ans = fpow(k, (long long)n * m - (long long)r * c);
    printf("%lld\n", ans);
    return 0;
  }
  if (ax > bx) {
    std::swap(ax, bx);
    std::swap(ay, by);
  }
  if (ay > by) {
    int diff = by + c - 1 - ay + 1;
    by = ay + c - 1 - diff + 1;
  }
  long long inter_area =
      (long long)(ay + c - 1 - by + 1) * (ax + c - 1 - bx + 1);
  long long graph_area = 2 * (long long)r * c - inter_area;
  long long out_area = (long long)n * m - graph_area;
  long long valid_area = (long long)r * c - inter_area;
  printf("%lld\n", fpow(k, out_area + valid_area));
  return 0;
}
