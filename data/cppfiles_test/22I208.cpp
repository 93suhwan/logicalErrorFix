#include <bits/stdc++.h>
using namespace std;
const int N = 105 + 5, mod = 998244353;
int n, k, q[N], J[N][N];
int a[N][N];
bool flag;
void dfs(int now) {
  if (now == k + 1) {
    for (int i = 1; i <= n - 1; ++i)
      if (a[k][i] > a[k][i + 1]) {
        flag = 1;
        return;
      }
    return;
  }
  int cnt[3];
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 1; i <= q[now]; ++i) ++cnt[a[now - 1][J[now][i]] + 1];
  for (int i = 0; i <= cnt[1]; ++i) {
    for (int j = 1; j <= n; ++j) a[now][j] = a[now - 1][j];
    for (int j = 1; j <= q[now]; ++j)
      if (j <= cnt[0] + i)
        a[now][J[now][j]] = -1;
      else
        a[now][J[now][j]] = 1;
    dfs(now + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", q + i);
    for (int j = 1; j <= q[i]; ++j) scanf("%d", J[i] + j);
  }
  flag = 0;
  for (int i = 1; i <= n; ++i) a[0][i] = 0;
  dfs(1);
  puts(flag ? "REJECTED" : "ACCEPTED");
  return 0;
}
