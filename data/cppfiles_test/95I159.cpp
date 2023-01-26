#include <bits/stdc++.h>
int n, s, base_10[15];
inline void solve() {
  scanf("%d%d", &s, &n);
  for (int i = n, cur; i > 1; --i) {
    cur = base_10[(int)log10(s - i)];
    s -= cur;
    printf("%d ", cur);
  }
  printf("%d\n", s);
}
int main() {
  int t;
  scanf("%d", &t);
  base_10[0] = 1;
  for (int i = 1; i <= 9; ++i) base_10[i] = base_10[i - 1] * 10;
  while (t--) solve();
  return 0;
}
