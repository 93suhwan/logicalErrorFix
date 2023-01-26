#include <bits/stdc++.h>
int n, s, suf[15], base_10[20];
inline int nine_count(int x) {
  int res = 0;
  while (x && x % 10 == 9) {
    ++res;
    x /= 10;
  }
  return res;
}
inline void solve() {
  scanf("%d%d", &s, &n);
  int m = 0;
  while (s) {
    ++m;
    suf[m] = s % 10 * base_10[m - 1] + suf[m - 1];
    s /= 10;
  }
  for (int i = m - 1; i >= 0; --i, --n) {
    if (suf[i] < n) {
      int x = nine_count(suf[i + 1] - n + 1);
      if (x > 0 && n > 1 && base_10[x] - 1 < suf[i + 1] - n + 1) {
        printf("%d %d ", base_10[x], suf[i + 1] - n + 2 - base_10[x]);
        for (int i = 2; i < n; ++i) printf("1 ");
      } else {
        printf("%d ", suf[i + 1] - n + 1);
        for (int j = 1; j < n; ++j) printf("1 ");
      }
      break;
    }
    if (n == 1) {
      printf("%d ", suf[i + 1]);
      break;
    }
    printf("%d ", suf[i + 1] - suf[i]);
  }
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  base_10[0] = 1;
  for (int i = 1; i <= 9; ++i) base_10[i] = base_10[i - 1] * 10;
  while (t--) solve();
  return 0;
}
