#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, b = 1;
  char c;
  do c = getchar();
  while ((c > '9' || c < '0') && c != '-');
  if (c == '-') b = 0;
  do x = x * 10 + c - '0', c = getchar();
  while (c >= '0' && c <= '9');
  return b ? x : -x;
}
const long long maxn = 4010;
long long i, j, k, n, m, T, a[maxn], son[maxn][2], root, cnt, dp[maxn][maxn],
    size[maxn];
void dfs(long long &root, long long L, long long R) {
  if (L > R) return;
  if (!root) root = ++cnt;
  long long Min = L;
  for (long long i = L; i <= R; i++)
    if (a[i] < a[Min]) Min = i;
  dfs(son[root][0], L, Min - 1);
  dfs(son[root][1], Min + 1, R);
  size[root] = size[son[root][0]] + size[son[root][1]] + 1;
  for (long long i = 0; i <= size[son[root][0]]; i++)
    for (long long j = 0; j <= size[son[root][1]]; j++) {
      dp[root][i + j] =
          max(dp[root][i + j],
              dp[son[root][0]][i] + dp[son[root][1]][j] - 2 * i * j * a[Min]);
      dp[root][i + j + 1] =
          max(dp[root][i + j + 1],
              dp[son[root][0]][i] + dp[son[root][1]][j] + m * a[Min] -
                  (2 * i * j + 2 * i + 2 * j + 1) * a[Min]);
    }
}
signed main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) a[i] = read();
  dfs(root, 1, n);
  long long Ans = 0;
  cout << dp[root][m] << endl;
}
