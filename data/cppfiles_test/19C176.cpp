#include <bits/stdc++.h>
using namespace std;
int t, n, a[11];
inline bool dfs(int x, int sum, bool flag) {
  if (x == n + 1) {
    if (!sum && flag) return 1;
    return 0;
  }
  return dfs(x + 1, sum + a[x], 1) || dfs(x + 1, sum - a[x], 1) ||
         dfs(x + 1, sum, flag);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (dfs(1, 0, 0))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
