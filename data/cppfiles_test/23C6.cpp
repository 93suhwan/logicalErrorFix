#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4010;
int n, m;
int a[MAXN];
int siz[MAXN];
unsigned long long dp[MAXN][MAXN];
int solve(int l, int r, int fa) {
  if (l > r) return 0;
  int minn = a[l], pos = l;
  for (int i = l + 1; i <= r; ++i) {
    if (a[i] < minn) {
      minn = a[i], pos = i;
    }
  }
  int ls = solve(l, pos - 1, pos), rs = solve(pos + 1, r, pos);
  siz[pos] = siz[ls] + siz[rs] + 1;
  int val = a[pos] - a[fa];
  for (int i = 0; i <= siz[ls]; ++i) {
    for (int j = 0; j <= siz[rs]; ++j) {
      if (i + j <= m)
        dp[pos][i + j] =
            max(dp[pos][i + j],
                dp[ls][i] + dp[rs][j] + 1ull * (m - i - j) * (i + j) * val);
      if (i + j + 1 <= m)
        dp[pos][i + j + 1] = max(
            dp[pos][i + j + 1],
            dp[ls][i] + dp[rs][j] + 1ull * (m - i - j - 1) * (i + j + 1) * val);
    }
  }
  return pos;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int root = solve(1, n, 0);
  printf("%llu\n", dp[root][m]);
}
