#include <bits/stdc++.h>
using namespace std;
const int MAXN = 410;
const int INF = 1e9;
int n, m;
char ch[MAXN];
bool mapn[MAXN][MAXN];
int pre[MAXN][MAXN];
int getval(int i, int j, int len) {
  int ret = 0;
  ret += pre[i + 4][j + len - 2] - pre[i + 4][j];
  for (int k = 1; k <= 3; ++k)
    ret += (!mapn[i + k][j]) + (!mapn[i + k][j + len - 1]);
  for (int k = i + 1; k <= i + 3; ++k) {
    ret += (len - 2 - (pre[k][j + len - 2] - pre[k][j]));
  }
  return ret;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", ch + 1);
      for (int j = 1; j <= m; ++j) {
        mapn[i][j] = (ch[j] == '1');
        pre[i][j] = pre[i][j - 1] + (!mapn[i][j]);
      }
    }
    int ans = INF;
    for (int len = 4; len <= m; ++len) {
      for (int i = 1; i <= m - len + 1; ++i) {
        int st = getval(n - 4, i, len);
        ans = min(ans, st + pre[n - 4][i + len - 2] - pre[n - 4][i]);
        for (int j = n - 5; j >= 1; --j) {
          st += (!mapn[j][i]) + (!mapn[j][i + len - 1]);
          st = min(st, getval(j, i, len));
          ans = min(ans, st + pre[j][i + len - 2] - pre[j][i]);
        }
      }
    }
    printf("%d\n", ans);
  }
}
