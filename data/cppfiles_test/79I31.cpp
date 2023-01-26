#include <bits/stdc++.h>
using namespace std;
int n, a[300010], b[300010];
int tre[300010], st[300010], dp[300010], lst[300010], from[300010];
int query(int x, int now) {
  int ret = -1;
  for (; x <= n; x += (x & -x))
    if (tre[x] && (ret == -1 || dp[tre[x]] < dp[ret]))
      ret = tre[x], from[now] = st[x];
  return ret;
}
void update(int x, int y) {
  int ee = x;
  for (; x; x -= (x & -x))
    if (!tre[x] || dp[tre[x]] > dp[y]) tre[x] = y, st[x] = ee;
}
vector<int> v[300010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] >= i)
      dp[i] = 1;
    else {
      lst[i] = query(i - a[i], i);
      if (lst[i] != -1)
        dp[i] = dp[lst[i]] + 1;
      else
        dp[i] = -1;
    }
    v[i + b[i]].push_back(i);
    if (dp[i] != -1)
      for (auto j : v[i]) update(j, i);
  }
  if (dp[n] == -1)
    puts("-1");
  else {
    printf("%d\n", dp[n]);
    int x = n;
    while (dp[x] != 1) {
      printf("%d ", from[x]);
      x = lst[x];
    }
    puts("0");
  }
}
