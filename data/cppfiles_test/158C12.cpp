#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int t, n, m, cnt[21], q[21][N], r[11], zf[11], res, ans[N], tem, num[N];
char s[11][N];
void cal() {
  tem = 0;
  for (int i = 1; i <= n; ++i) tem -= zf[i] * r[i];
  for (int i = 1; i <= m; ++i) num[i] = 0;
  for (int i = 0; i <= 20; ++i) cnt[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      num[j] += zf[i] * (s[i][j] - '0');
    }
  }
  for (int i = 1; i <= m; ++i) q[num[i] + 10][++cnt[num[i] + 10]] = i;
  int sum = 0;
  for (int i = 0; i <= 20; ++i) {
    tem += (i - 10) * (sum + 1 + sum + cnt[i]) * cnt[i] / 2;
    sum += cnt[i];
  }
}
void dfs(int x) {
  if (x == n + 1) {
    cal();
    if (tem > res) {
      res = tem;
      int top = 0;
      for (int i = 0; i <= 20; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
          ans[q[i][j]] = ++top;
        }
      }
    }
    return;
  }
  zf[x] = 1;
  dfs(x + 1);
  zf[x] = -1;
  dfs(x + 1);
}
void slv() {
  res = -1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", r + i);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  dfs(1);
  for (int i = 1; i <= m; ++i) printf("%d ", ans[i]);
  puts("");
}
int main() {
  scanf("%d", &t);
  while (t--) slv();
}
