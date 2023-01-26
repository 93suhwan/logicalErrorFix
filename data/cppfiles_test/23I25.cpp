#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[4005];
int ls[4005], rs[4005], siz[4005];
vector<int> S;
void build() {
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    while (S.size() && a[S.back()] >= a[i]) {
      cur = S.back();
      S.pop_back();
    }
    if (S.size()) rs[S.back()] = i;
    ls[i] = cur;
    S.push_back(i);
  }
}
long long dp[4005][4005];
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
void dfs1(int u) {
  for (int i = 1; i <= n; i++) dp[u][i] = -1145141919810114514;
  siz[u] = 1;
  if (ls[u]) dfs1(ls[u]);
  siz[u] += siz[ls[u]];
  if (rs[u]) dfs1(rs[u]);
  siz[u] += siz[rs[u]];
  for (int i = 0; i <= siz[ls[u]]; i++) {
    for (int j = 0; j <= siz[rs[u]]; j++) {
      dp[u][i + j] =
          Max(dp[u][i + j], dp[ls[u]][i] + dp[rs[u]][j] - 2 * a[u] * i * j);
    }
  }
  for (int i = 1; i <= siz[u]; i++)
    dp[u][i] = Max(dp[u][i - 1] + a[u] * m - a[u] * (2 * i - 1), dp[u][i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build();
  dfs1(S[0]);
  printf("%lld\n", dp[S[0]][m]);
  return 0;
}
