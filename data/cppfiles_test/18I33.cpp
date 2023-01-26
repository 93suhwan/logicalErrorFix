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
int work() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) f[i] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  try {
    for (int i = 0; i < n; i++) ans = max(ans, dp(i));
    printf("%d\n", ans);
  } catch (...) {
    puts("-1");
  }
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
