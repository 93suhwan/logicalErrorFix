#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 998244353;
const int N = 1000005;
int n, a[N];
long long all, f[N], sum[N];
int tp, s[N];
void update(int x) {
  while (tp && a[x] <= a[s[tp]]) {
    all = (all - a[s[tp]] * (sum[s[tp] - 1] - sum[s[tp - 1] - 1]) % mod + mod) %
          mod;
    --tp;
  }
  s[++tp] = x;
  all = (all + a[s[tp]] * (sum[s[tp] - 1] - sum[s[tp - 1] - 1]) % mod + mod) %
        mod;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n + 1; i++) scanf("%d", &a[i]);
  f[1] = sum[1] = 1;
  for (int i = 2; i <= n + 1; i++) {
    update(i);
    f[i] = (((i % 2 == 0) ? all : -all) + mod) % mod;
    sum[i] = (sum[i - 1] + (i % 2 ? 1 : -1) * f[i] % mod + mod) % mod;
  }
  long long ans = f[n + 1];
  ans = (ans % mod + mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
