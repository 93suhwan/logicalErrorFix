#include <bits/stdc++.h>
const int MAXN = 105;
int dp[MAXN][MAXN][MAXN], C[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int N, M, K, P;
  std::cin >> N >> M >> K >> P;
  auto add = [&](int a, int b) { return a -= (a += b) >= P ? P : 0; };
  auto incr = [&](int& a, int b) { a -= (a += b) >= P ? P : 0; };
  for (int i = 0; i <= N; ++i)
    for (int j = *C[i] = 1; j <= i; ++j)
      C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  std::function<int(int, int, int)> solve = [&](int sz, int c, int dep) {
    if (vis[sz][c][dep]) return dp[sz][c][dep];
    if (sz + 1 < c * 2 || c > sz) return 0;
    if (sz == 0) return c ? 0 : 1;
    if (dep > M && c) return 0;
    vis[sz][c][dep] = true;
    int& ans = dp[sz][c][dep] = 0;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j <= c - (dep == M) && j <= i; ++j)
        incr(ans, 1ll * solve(i, j, dep + 1) *
                      solve(sz - i - 1, c - j - (dep == M), dep + 1) % P *
                      C[sz - 1][i] % P);
    return ans;
  };
  std::cout << solve(N, K, 1) << '\n';
  return 0;
}
