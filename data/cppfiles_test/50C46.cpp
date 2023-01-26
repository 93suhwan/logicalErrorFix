#include <bits/stdc++.h>
const int maxn = 200005, mod = 998244353;
int n, top, ans;
int a[maxn], stk[maxn][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int val = (ans + (i == 1)) % mod;
    ans = (ans - 1ll * val * a[i] % mod + mod) % mod;
    while (top > 0 && stk[top][1] > a[i])
      ans = (ans + 1ll * stk[top][0] * (stk[top][1] - a[i])) % mod,
      val = (val + stk[top][0]) % mod, top--;
    stk[++top][0] = val, stk[top][1] = a[i];
  }
  printf("%d\n", n % 2 == 0 ? ans : (mod - ans) % mod);
  return 0;
}
