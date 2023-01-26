#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int ans[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int jsq = 1; jsq <= T; jsq++) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a + b > n - 2 || abs(a - b) > 1) {
      puts("-1");
      continue;
    }
    if (a == b) {
      for (int i = 1; i <= a + 1; i++) {
        ans[i * 2 - 1] = i;
        ans[i * 2] = i + a + 1;
      }
      for (int i = 2 * a + 3; i <= n; i++) ans[i] = i;
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      puts("");
      continue;
    }
    bool flag = 0;
    if (a < b) {
      flag = 1;
      swap(a, b);
    }
    for (int i = 1; i <= a; i++) {
      ans[i * 2] = i;
      ans[i * 2 - 1] = i + a;
    }
    for (int i = 2 * a + 1; i <= n; i++) ans[i] = i;
    for (int i = 1; i <= n; i++) printf("%d ", flag ? ans[i] : n - ans[i] + 1);
    puts("");
  }
  return 0;
}
