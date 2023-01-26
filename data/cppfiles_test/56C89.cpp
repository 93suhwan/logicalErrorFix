#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
long long k, n;
long long v;
map<long long, long long> dp[4], col, exist;
inline long long ksm(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % 1000000007)
    if (y & 1) ret = ret * x % 1000000007;
  return ret;
}
long long dfs(long long x, long long c, long long dep) {
  if (dp[c].count(x)) return dp[c][x];
  if (!exist[x]) return dp[c][x] = ksm(2, (1ll << dep) - 2);
  if (col[x] && col[x] != c) return dp[c][x] = 0;
  if (x * 2 > (1ll << k) - 1) return dp[c][x] = 1;
  long long ret = 0;
  for (long long i = 1; i <= 3; i++)
    if (i != c)
      for (long long j = 1; j <= 3; j++)
        if (j != c)
          ret = (ret + dfs(x << 1ll, i, dep - 1) *
                           dfs(x << 1ll | 1ll, j, dep - 1) % 1000000007) %
                1000000007;
  return dp[c][x] = ret;
}
signed main() {
  k = rd(), n = rd();
  char s[10];
  for (long long i = 1; i <= n; i++) {
    long long v = rd();
    scanf("%s", s + 1);
    if (s[1] == 'w' || s[1] == 'y') col[v] = 1;
    if (s[1] == 'g' || s[1] == 'b') col[v] = 2;
    if (s[1] == 'r' || s[1] == 'o') col[v] = 3;
    while (v) exist[v] = 1, v >>= 1;
  }
  long long ans = (dfs(1, 1, k) + dfs(1, 2, k) + dfs(1, 3, k)) % 1000000007;
  ans = ans * ksm(2, (1ll << k) - 1 - n) % 1000000007;
  printf("%lld\n", ans);
  return 0;
}
