#include <bits/stdc++.h>
const int N = 300005;
int n, m, s[N];
char str[N];
int x, y;
int b(int t) { return (s[t - 1] - s[x - 1]) - (s[y] - s[t]); }
int work() {
  int l = x, r = y, mid;
  if (!b(x)) return x;
  if (!b(y)) return y;
  while (l < r) {
    mid = l + r >> 1;
    if (!b(mid)) return mid;
    if (1ll * b(l) * b(mid) < 0)
      r = mid;
    else
      l = mid;
  }
  return -1;
}
int main() {
  int task;
  for (scanf("%d", &task); task--;) {
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
      s[i] = s[i - 1] + (i & 1 ? 1 : -1) * (str[i] == '+' ? 1 : -1);
    }
    while (m--) {
      scanf("%d%d", &x, &y);
      if (s[y] == s[x - 1]) {
        puts("0");
      } else if (y - x & 1) {
        puts("2");
        printf("%d ", x++);
        printf("%d\n", work());
      } else {
        puts("1");
        printf("%d\n", work());
      }
    }
  }
  return 0;
}
