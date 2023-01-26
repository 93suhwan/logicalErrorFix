#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], ans;
void solve() {
  scanf("%d", &n), ans = 1e9;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  int t0 = 0, t1 = 0, t2 = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] % 3 == 0) t0++;
    if (a[i] % 3 == 1) t1++;
    if (a[i] % 3 == 2) t2++;
  }
  if (a[n] % 3 == 0) {
    if (t1 == 0 && t2 == 0) ans = min(ans, a[n] / 3);
    ans = min(ans, a[n] / 3 + 1);
  }
  if (a[n] % 3 == 1) {
    if (a[1] != 1 && a[n - 1] != a[n] - 1) ans = min(ans, a[n] / 3 + 1);
    if (t2 == 0) ans = min(ans, a[n] / 3 + 1);
    ans = min(ans, a[n] / 3 + 2);
  }
  if (a[n] % 3 == 2) {
    if (t1 == 0) ans = min(ans, a[n] / 3 + 1);
    ans = min(ans, a[n] / 3 + 2);
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
