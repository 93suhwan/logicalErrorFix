#include <bits/stdc++.h>
using namespace std;
int read();
const int N = 4005;
int n, m, st[N], top, ch[N][2], siz[N];
long long dp[N][N], a[N];
void dfs(int u) {
  if (!u) return;
  int lc = ch[u][0], rc = ch[u][1];
  dfs(lc);
  dfs(rc);
  siz[u] = siz[lc] + siz[rc] + 1;
  for (int i = (0); i <= (siz[lc]); ++i)
    for (int j = (0); j <= (siz[rc]); ++j) {
      dp[u][i + j] =
          max(dp[u][i + j], dp[lc][i] + dp[rc][j] - 2ll * i * j * a[u]);
      dp[u][i + j + 1] = max(
          dp[u][i + j + 1], dp[lc][i] + dp[rc][j] + m * a[u] -
                                2ll * i * j * a[u] - (i + j) * a[u] * 2 - a[u]);
    }
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int i = (1); i <= (n); ++i) {
    while (top && a[st[top]] > a[i]) ch[i][0] = st[top--];
    if (top) ch[st[top]][1] = i;
    st[++top] = i;
  }
  dfs(st[1]);
  cout << dp[st[1]][m] << endl;
  return 0;
}
