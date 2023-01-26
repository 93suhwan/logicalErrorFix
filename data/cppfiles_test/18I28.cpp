#include <bits/stdc++.h>
using namespace std;
const int N = 2.1e5, mod = 998244353;
int a[N], n, d;
bool inst[N];
int f[N];
int dp(int k) {
  if (a[k] == 0) return 0;
  if (f[k] != -1) return f[k];
  if (inst[k]) throw 0;
  inst[k] = 1;
  f[k] = dp((k - d + n) % n) + 1;
  inst[k] = 0;
  return f[k];
}
bool vis[N];
int work() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++)
    if (a[i] == 0)
      f[i] = 0;
    else
      f[i] = 1e9;
  for (int _ = 1; _ <= 2; _++)
    for (int i = 0; i < n; i++) {
      int to = (i + d) % n;
      if (a[i] == 0 && a[to] == 1) f[to] = f[i] + 1, a[to] = 0;
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
  if (ans >= 1e9)
    printf("%d\n", ans);
  else
    puts("-1");
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
