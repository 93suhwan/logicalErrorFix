#include <bits/stdc++.h>
using namespace std;
long long a[100000], lim, n, flag;
void DFS(long long x, long long y) {
  if (x > n) {
    if (y == a[lim]) flag = 1;
    return;
  }
  if (flag) return;
  DFS(x + 1, y);
  if (x != lim) {
    DFS(x + 1, y + a[x]);
    DFS(x + 1, y - a[x]);
  }
}
inline void work() {
  lim = flag = n = 0;
  memset(a, 0, sizeof(a));
  scanf("%lld", &n);
  for (register long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (lim = 1; lim <= n; ++lim) {
    DFS(1, 0);
    if (flag) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) work();
}
