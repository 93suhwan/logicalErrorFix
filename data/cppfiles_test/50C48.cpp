#include <bits/stdc++.h>
using namespace std;
int a[200005], dp[200005], stk[200005], top = 0;
int sum[200005];
int Sum(int x, int y) {
  if (!x) return sum[y];
  if ((y - x + 1) & 1) return (sum[y] + sum[x - 1]) % 998244353;
  return (sum[y] - sum[x - 1] + 998244353) % 998244353;
}
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  dp[0] = 1;
  sum[0] = 1;
  for (i = 1; i <= n; i++) {
    while (top && a[stk[top]] >= a[i]) top--;
    dp[i] = 1ll * a[i] * Sum(stk[top], i - 1) % 998244353;
    if (stk[top]) {
      if ((i - stk[top]) & 1)
        dp[i] = (dp[i] - dp[stk[top]] + 998244353) % 998244353;
      else
        dp[i] = (dp[i] + dp[stk[top]]) % 998244353;
    }
    sum[i] = (dp[i] - sum[i - 1] + 998244353) % 998244353;
    stk[++top] = i;
  }
  printf("%d\n", dp[n]);
  return 0;
}
