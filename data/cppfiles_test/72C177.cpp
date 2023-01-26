#include <bits/stdc++.h>
const int inf = 2e9;
int T, n, k, n2, cnt, m, a[12], b[12], v[12];
long long ans;
inline long long min(long long x, long long y) { return x < y ? x : y; }
long long dfs(int x) {
  if (x == 0) return 0;
  int t = std::lower_bound(b + 1, b + m + 1, a[x]) - b;
  if (t > m) return inf;
  if (b[t] == a[x]) {
    int t2 = dfs(x - 1);
    if (t2 != inf) return 1ll * b[t] * v[x] + t2;
    if (t == m) return inf;
    return 1ll * b[t + 1] * v[x] + 1ll * b[1] * (v[x] - 1) / 9;
  }
  return 1ll * b[t] * v[x] + 1ll * b[1] * (v[x] - 1) / 9;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k), ans = inf;
    n2 = n / 10, a[cnt = 1] = n % 10, v[1] = 1;
    while (n2) a[++cnt] = n2 % 10, v[cnt] = v[cnt - 1] * 10, n2 /= 10;
    for (int i = 1, j; i < 1024; ++i)
      if (__builtin_popcount(i) == k) {
        m = 0, j = i;
        while (j) b[++m] = __builtin_ctz(j), j ^= (1 << b[m]);
        ans = min(ans, dfs(cnt));
      }
    printf("%d\n", ans);
  }
  return 0;
}
