#include <bits/stdc++.h>
const int M = 2000;
int T, n, x, ans, f0[M + 10], f1[M + 10];
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
void work() {
  for (int i = 0; i <= M; ++i) f0[i] = i;
  scanf("%d", &n), ans = 114514;
  while (n--) {
    scanf("%d", &x), memset(f1, 0x3f, sizeof f1);
    for (int i = 0; i <= M; ++i)
      i - x >= 0 && (f1[i] = min(f1[i], max(f0[i - x], i))),
          i + x <= M && (f1[i] = min(f1[i], f0[i + x]));
    memcpy(f0, f1, sizeof f0);
  }
  for (int i = 0; i <= M; ++i) ans = min(ans, f0[i]);
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
