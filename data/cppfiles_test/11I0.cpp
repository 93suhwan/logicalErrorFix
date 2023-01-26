#include <bits/stdc++.h>
const int MAX_N = 2e5 + 10;
int n, ma, a[MAX_N], f[MAX_N], BIT[MAX_N];
int lowbit(int x) { return x & (-x); }
int getf(int x) {
  int r = 0;
  for (; x; x -= lowbit(x)) r = std::max(r, BIT[x]);
  return r;
}
void add(int x, int a) {
  for (; x <= ma; x += lowbit(x)) BIT[x] = std::max(BIT[x], a);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ma = std::max(ma, a[i]);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (i - a[i] < 0)
      f[i] = 0;
    else
      f[i] = std::max(1, getf(i - a[i]) + 1);
    add(a[i], f[i]);
    res = std::max(res, f[i]);
  }
  printf("%d\n", res);
  return 0;
}
