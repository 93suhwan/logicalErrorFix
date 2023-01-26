#include <bits/stdc++.h>
int T;
int n;
int a[200005], tag[200005];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) tag[i] = 1;
  for (int p = 0; p < 30; p++) {
    int tot = 0;
    for (int i = 1; i <= n; i++) tot += (a[i] >> p) & 1;
    for (int i = 1; i <= n; i++)
      if (tot % i != 0) tag[i] = 0;
  }
  for (int i = 1; i <= n; i++)
    if (tag[i]) printf("%d ", i);
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
