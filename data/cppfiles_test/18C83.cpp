#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1000010;
int n, d;
int a[N];
int f[N];
bool st[N];
int dfs(int p) {
  if (st[p]) return f[p] = -inf;
  if (f[p] != -1) return f[p];
  if (a[p] == 0) return 0;
  st[p] = 1;
  f[p] = dfs((p + n - d) % n) + 1;
  st[p] = 0;
  return f[p];
}
void solve() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    f[i] = -1;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int t = dfs(i);
    if (t < 0) {
      puts("-1");
      return;
    } else {
      res = max(res, t);
    }
  }
  printf("%d\n", res);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(st, false, sizeof st);
    solve();
  }
  return 0;
}
