#include <bits/stdc++.h>
using namespace std;
int n, m, rt, sz[4005];
int st[4005], top, ch[4005][2];
long long dp[4005][4005], a[4005];
void dfs(int now) {
  sz[now] = 1;
  for (int i = 0; i < 2; i++)
    if (ch[now][i]) {
      int to = ch[now][i];
      dfs(to);
      for (int j = sz[now]; j >= 0; j--)
        for (int k = sz[to]; k >= 0; k--)
          dp[now][j + k] =
              max(dp[now][j + k],
                  dp[now][j] + dp[to][k] + k * (m - k) * (a[to] - a[now]));
      sz[now] += sz[to];
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    while (top && a[st[top]] > a[i]) ch[i][0] = st[top--];
    if (top) ch[st[top]][1] = i;
    st[++top] = i;
  }
  for (int i = 1; i <= n; i++)
    if (!rt || a[i] < a[rt]) rt = i;
  dfs(rt);
  printf("%lld", dp[rt][m]);
}
