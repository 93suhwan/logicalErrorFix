#include <bits/stdc++.h>
const int Mod = 1e9 + 7;
int f[100005];
int main() {
  f[1] = 1;
  for (register int i = 2; i != 100001; ++i) {
    f[i] = ((i << 1) - 1ll) * f[i - 1] % 1000000007 * (i << 1) % 1000000007;
  }
  int n;
  scanf("%d", &n);
  for (register int i = n; i != 0; --i) {
    scanf("%d", &n);
    printf("%d\n", f[n]);
  }
}
