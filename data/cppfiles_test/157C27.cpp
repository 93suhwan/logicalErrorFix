#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, k, sum, ans, tem;
int fac[N], inv[N], pre[N], suf[N];
char s[N];
int C(int i, int j) {
  if (i < j) return 0;
  return 1ll * fac[i] * inv[j] % mod * inv[i - j] % mod;
}
int qp(int x, int y) {
  int res = 1;
  while (y) {
    if (y % 2) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
void add(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  ans = 1;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + s[i] - '0';
  }
  for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + s[i] - '0';
  if (pre[n] < k) {
    cout << 1;
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * i * fac[i - 1] % mod;
  inv[n] = qp(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      tem = pre[j] - pre[i - 1];
      if (tem > k) continue;
      if (s[i] == '0') tem--;
      if (s[j] == '0') tem--;
      add(ans, C(j - i - 1, tem));
    }
  }
  printf("%d\n", ans);
}
