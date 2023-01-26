#include <bits/stdc++.h>
using namespace std;
int a[300005], b[300005], f[300005];
queue<int> q;
int main() {
  int n, i, j, k, u, v, up = n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  q.push(n);
  f[n] = n;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (i = u - a[u]; i <= min(u, up); i++) {
      v = i + b[i];
      if (f[v] != 0) continue;
      f[v] = u;
      q.push(v);
    }
    up = min(u - a[u], up);
  }
  if (f[0] == 0) {
    printf("-1");
    return 0;
  }
  vector<int> ans;
  for (i = 0; i < n; i = f[i]) ans.push_back(i);
  printf("%d\n", ans.size());
  for (i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
  return 0;
}
