#include <bits/stdc++.h>
using namespace std;
int n, top;
long long x, ans;
const int N = 2e5 + 5;
const int mo = 998244353;
long long a[N], f[N], sum[N], g[N], h[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  f[0] = 1;
  sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    while (a[i] <= a[g[top]]) top--;
    if (top)
      x = sum[i - 1] - sum[g[top] - 1];
    else
      x = sum[i - 1];
    x = -x * a[i] % mo;
    f[i] = (h[top] + x) % mo;
    sum[i] = (sum[i - 1] + f[i]) % mo;
    g[++top] = i;
    h[top] = (h[top - 1] + x) % mo;
  }
  ans = f[n];
  if (n % 2) ans = -f[n];
  ans = (ans % mo + mo) % mo;
  printf("%d\n", ans);
}
