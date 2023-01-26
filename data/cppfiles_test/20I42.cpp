#include <bits/stdc++.h>
using namespace std;
const int MAXN = 410;
const int INF = 1e9;
int n, m;
char ch[MAXN];
bool mapn[MAXN][MAXN];
int val[MAXN][MAXN];
int pre[MAXN][MAXN];
int getval(int i, int j) {
  int ret = 0;
  for (int k = 1; k <= 2; ++k) ret += (!mapn[i + 4][j + k]);
  for (int k = 1; k <= 3; ++k) ret += (!mapn[i + k][j]) + (!mapn[i + k][j + 3]);
  for (int k = i + 1; k <= i + 3; ++k) {
    for (int l = j + 1; l <= j + 2; ++l) {
      ret += mapn[k][l];
    }
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
    for (int i = 1; i <= n - 4; ++i) {
      for (int j = 1; j <= m - 3; ++j) {
        val[i][j] = getval(i, j);
      }
    }
    int ans = INF;
    for (int j = 1; j <= m - 3; ++j) {
      for (int i = n - 4; i >= 1; --i) {
        int nowmin = val[i][j];
        ans = min(ans, nowmin + pre[i][j + 2] - pre[i][j]);
        for (int k = n - 5; k >= 1; --k) {
          int now = val[k][j];
          nowmin += (!mapn[k][j]) + (!mapn[k][j + 2]);
          nowmin = min(nowmin, now);
          ans = min(ans, nowmin + pre[k][j + 2] - pre[k][j]);
        }
      }
    }
    printf("%d\n", ans);
  }
}
