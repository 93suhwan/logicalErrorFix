#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010];
void solve(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = n - 1, j = a[n]; i; i--)
    if (a[i] > j) {
      j = a[i];
      ans++;
    }
  printf("%d\n", ans);
  return;
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
