#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, cnt, a[N], x[N], y[N], fa[N], ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < N; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1)
      scanf("%d", &x[i]);
    else
      scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = n; i > 0; i--) {
    if (a[i] == 1)
      ans[++cnt] = fa[x[i]];
    else
      fa[x[i]] = fa[y[i]];
  }
  for (int i = cnt; i > 0; i--) printf("%d ", ans[i]);
  printf("\n");
}
