#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 10;
const int Inf = 0x7f7f7f7f;
const long long Inf_ll = 1ll * Inf * Inf;
const int Mod = 1e9 + 7;
const double eps = 1e-7;
int n, a[15], len, b[15];
void solve() {
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  len = 0;
  int x = n;
  while (x) a[len++] = x % 10, x /= 10;
  int nn = (1 << len), ans = 0;
  for (int i = 0; i < nn; i++) {
    if ((i & 1) || (i >> 1 & 1)) continue;
    for (int j = 0; j < len; j++) b[j] = a[j];
    for (int j = 0; j < len; j++) {
      if (i >> j & 1) b[j - 2] += 10, b[j]--;
    }
    int tmp = 1;
    bool flag = true;
    for (int j = 0; j < len; j++) {
      if (b[j] < 0)
        tmp = 0;
      else if (b[j] == 0)
        continue;
      else if (b[j] <= 9)
        tmp *= b[j] + 1;
      else
        tmp *= 19 - b[j], flag = false;
    }
    if (flag) tmp -= 2;
    ans += tmp;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int _ = 1; _ <= T; _++) {
    solve();
  }
  return 0;
}
