#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, a, b, x, y, ans = 114514;
    scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y);
    if (a <= x)
      ans = min(ans, x - a);
    else
      ans = min(ans, a - x + 2 * (n - a));
    if (b <= y)
      ans = min(ans, y - b);
    else
      ans = min(ans, b - y + 2 * (m - b));
    printf("%d\n", ans);
  }
}
