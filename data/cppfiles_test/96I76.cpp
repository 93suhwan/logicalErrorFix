#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 998244353;
int in[501][510], dp[501][501], c[501][501];
void add(int &a, long long b) {
  a = (a + b) % mod;
  return;
}
int dfs(int u, int x) {
  if (u <= 1) return !u;
  if (dp[u][x]) return dp[u][x];
  if (x <= u - 1)
    dp[u][x] = in[x][u];
  else {
    for (int i = u; i >= 0; i--)
      add(dp[u][x],
          (long long)dfs(i, x - (u - 1)) * c[u][i] % mod * in[u - 1][u - i]);
  }
  return dp[u][x];
}
int main() {
  for (int i = 0; i <= 500; i++) {
    in[i][0] = 1;
    c[i][0] = 1;
    for (int j = 1; j <= 500; j++)
      add(in[i][j], (long long)in[i][j - 1] * i),
          add(c[i][j], c[i - 1][j - 1] + c[i - 1][j]);
  }
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", dfs(a, b));
  return 0;
}
