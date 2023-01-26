#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
char s[N], t[N];
int dp[2][N][N], nxt[N][2], n, m, fail[N];
void update(int &x, int y) {
  if (y == -1) return;
  if (x == -1)
    x = y;
  else
    x = min(x, y);
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 1; i <= m; i++) {
    string tmp = "";
    for (int j = 1; j < i; j++) tmp += t[j];
    string ntmp = tmp + '0';
    nxt[i][0] = 1;
    for (int j = 0; j < ntmp.size(); j++) {
      int flag = 0, pos;
      for (int k = j; k < ntmp.size(); k++) {
        if (k - j + 1 >= m) {
          flag = 1;
          break;
        }
        if (t[k - j + 1] != ntmp[k]) flag = 1;
        pos = k - j + 1;
      }
      if (!flag) {
        nxt[i][0] = pos + 1;
        break;
      }
    }
    ntmp = tmp + '1';
    nxt[i][1] = 1;
    for (int j = 0; j < ntmp.size(); j++) {
      int flag = 0, pos;
      for (int k = j; k < ntmp.size(); k++) {
        if (k - j + 1 >= m) {
          flag = 1;
          break;
        }
        if (t[k - j + 1] != ntmp[k]) flag = 1;
        pos = k - j + 1;
      }
      if (!flag) {
        nxt[i][1] = pos + 1;
        break;
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][1] = 0;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    memset(dp[p ^ 1], -1, sizeof(dp[p ^ 1]));
    for (int j = 0; j <= n - m + 1; j++) {
      for (int k = 1; k <= m; k++) {
        if (dp[p][j][k] == -1) continue;
        if (t[k] == '0') {
          int cost = dp[p][j][k] + (s[i] != '0');
          if (k == m)
            update(dp[p ^ 1][j + 1][nxt[k][0]], cost);
          else
            update(dp[p ^ 1][j][k + 1], cost);
        } else {
          int cost = dp[p][j][k] + (s[i] != '0');
          update(dp[p ^ 1][j][nxt[k][0]], cost);
        }
        if (t[k] == '1') {
          int cost = dp[p][j][k] + (s[i] != '1');
          if (k == m)
            update(dp[p ^ 1][j + 1][nxt[k][1]], cost);
          else
            update(dp[p ^ 1][j][k + 1], cost);
        } else {
          int cost = dp[p][j][k] + (s[i] != '1');
          update(dp[p ^ 1][j][nxt[k][1]], cost);
        }
      }
    }
    p ^= 1;
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int ans = -1;
    for (int j = 1; j <= m; j++) update(ans, dp[p][i][j]);
    cout << ans;
    if (i != n - m + 1)
      cout << " ";
    else
      cout << "\n";
  }
  return 0;
}
