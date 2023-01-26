#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long mod = 1e9 + 7;
int n, m, f[N * 2], sz[N * 2];
char s[N];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
void join(int u, int v) {
  int fa = find(u), fb = find(v);
  if (fa != fb) f[fb] = fa, sz[fa] += sz[fb];
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    int flag = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n * 2; i++) {
      f[i] = i;
      if (i > n)
        sz[i] = 1;
      else
        sz[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d %d %s", &u, &v, s);
      int uc = u, vc = v, ui = u + n, vi = v + n;
      if (s[0] == 'i') {
        if (find(uc) == find(vc)) flag = 1;
        join(uc, vi);
        join(ui, vc);
      } else {
        if (find(uc) == find(vi)) flag = 1;
        join(uc, vc);
        join(ui, vi);
      }
    }
    if (flag)
      puts("-1");
    else {
      int ans = 0;
      for (int i = 1; i <= n; i++)
        if (f[i] == i) ans += max(sz[i], sz[i + n]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
