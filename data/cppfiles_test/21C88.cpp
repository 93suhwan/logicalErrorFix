#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n, m, k, p;
long long C[maxn][maxn], fac[maxn], dp[maxn][maxn][maxn];
long long solve(int len, int dep, int tot) {
  if (len == 0) return tot == 0;
  if (dep == 1) return tot == 1 ? fac[len] : 0;
  if (2 * (tot - 1) > len) return 0;
  if (dp[len][dep][tot] >= 0) return dp[len][dep][tot];
  long long ans = 0;
  for (int pos = 1; pos <= len; ++pos)
    for (int x = max(0, (2 * tot - 2 - len + pos) / 2); 2 * (x - 1) <= pos - 1;
         ++x)
      ans = (ans + C[len - 1][pos - 1] * solve(pos - 1, dep - 1, x) % p *
                       solve(len - pos, dep - 1, tot - x)) %
            p;
  return dp[len][dep][tot] = ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  C[0][0] = fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    fac[i] = i * fac[i - 1] % p;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%lld", solve(n, m, k));
  return 0;
}
