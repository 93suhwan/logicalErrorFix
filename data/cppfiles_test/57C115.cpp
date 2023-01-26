#include <bits/stdc++.h>
int T, n, f, a[2100], b[2100];
void rev(int x) {
  (x & 1) || (++x), printf("%d ", x);
  for (int i = 1, t; i <= (x >> 1); ++i)
    b[a[i]] = x - i + 1, b[a[x - i + 1]] = i, t = a[i], a[i] = a[x - i + 1],
    a[x - i + 1] = t;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), f = 0;
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i), b[a[i]] = i, f |= (a[i] - i & 1);
    if (f) {
      puts("-1");
      continue;
    }
    printf("%d\n", (n >> 1) * 5);
    for (int i = n - 1; i; i -= 2)
      rev(b[i + 1]), rev(b[i] - 1), rev(b[i] + 1), rev(3), rev(i + 1);
    putchar('\n');
  }
  return 0;
}
