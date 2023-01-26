#include <bits/stdc++.h>
using std::max;
using std::min;
using std::string;
using std::vector;
int const MAXN = 100011;
int a[MAXN];
int sgn(int x) {
  if (x == 0) return 0;
  if (x < 0) return -1;
  return 1;
}
int main() {
  int T(1);
  scanf("%d", &T);
  while (T--) {
    int n, m, ans(0);
    bool flag(false);
    scanf("%d", &n);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[i] <= a[i - 1]) flag = true;
    }
    puts(((n & 1) == 0 or flag) ? "YES" : "NO");
  }
  return 0;
}
