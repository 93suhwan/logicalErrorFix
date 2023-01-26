#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5, M = 510;
const long long mod = 998244353;
const long long inf = 1e12;
const double pai = acos(-1);
long long T, n, m;
long long va[N];
long long dp[M][M];
long long C[M][M];
void init();
long long ksm(long long a, long long b);
long long dfs(long long now, long long maxn);
signed main() {
  init();
  cin >> n >> m;
  cout << dfs(n, m) << "\n";
  return 0;
}
long long dfs(long long now, long long maxn) {
  if (now == 0) return 1;
  if (now == 1) return 0;
  if (dp[now][maxn]) return dp[now][maxn];
  if (maxn < now) return ksm(maxn, now) % mod;
  long long res = 0;
  for (long long i = 0; i <= now; i++) {
    res += dfs(now - i, maxn - now + 1) % mod * ksm(now - 1, i) % mod *
           C[now][i] % mod;
  }
  dp[now][maxn] = res % mod;
  return dp[now][maxn];
}
long long ksm(long long a, long long b) {
  long long sum = 1;
  while (b) {
    if (b & 1) sum = sum * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return sum;
}
void init() {
  C[0][0] = 1;
  for (long long i = 1; i < M; i++) {
    for (long long j = 0; j <= i; j++) {
      if (j == 0)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
