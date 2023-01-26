#include <bits/stdc++.h>
using namespace std;
const int N = 520, M = 512;
int f[N], g[N];
int a[int(1e6)];
int n;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (register int i = 1; i < M; ++i) f[i] = 1e9;
  f[0] = -1;
  for (register int i = 1; i <= n; ++i) {
    for (register int k = 0; k < M; ++k) {
      g[k] = f[k];
      if (f[k xor a[i]] < a[i]) g[k] = min(f[k], a[i]);
    }
    swap(f, g);
  }
  int cnt = 0;
  for (register int i = 0; i < M; ++i)
    if (f[i] != int(1e9)) ++cnt;
  printf("%d\n", cnt);
  for (register int i = 0; i < M; ++i)
    if (f[i] != int(1e9)) printf("%d ", i);
  puts("");
  return 0;
}
