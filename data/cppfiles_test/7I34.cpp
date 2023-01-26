#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 507;
const int inf = 0x3f3f;
string a, b;
short dp[N][N][N];
void upd(short &x, short y) { x = min(x, y); }
int nxt[N][2];
int cnt[N][N];
void getNext(int m) {
  for (int i = 1; i <= m + 1; i++) {
    {
      nxt[i][0] = m + 1;
      string s = '0' + (i <= m ? b.substr(i) : "");
      for (int j = i - 1; j <= m; j++) {
        string cur = b.substr(j);
        if (s.substr(0, cur.size()) == cur) nxt[i][0] = j;
      }
    }
    {
      nxt[i][1] = m + 1;
      string s = '1' + (i <= m ? b.substr(i) : "");
      for (int j = i - 1; j <= m; j++) {
        string cur = b.substr(j);
        if (s.substr(0, cur.size()) == cur) {
          nxt[i][1] = j;
          break;
        }
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  cin >> a;
  a = ' ' + a;
  cin >> b;
  b = ' ' + b;
  getNext(m);
  for (int j = 1; j <= n; j++) {
    int now = 0;
    for (int i = j, k = m; i >= 1 && k >= 1; i--, k--) {
      if (a[i] != b[k]) ++now;
      cnt[i][j] = now;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) dp[i][j][k] = inf;
  for (int j = 0; j <= m; j++) {
    if (j < m)
      dp[0][j][0] = cnt[1][j];
    else
      dp[0][j][1] = cnt[1][j];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m && i + j <= n; j++) {
      int p = m - j + 1;
      for (int d = 0; d <= 1; d++) {
        int np = nxt[p][d];
        assert(m - np + 1 >= 0);
        for (int k = 0; k <= n - m + 1; k++) {
          if (j == m) {
            if (k == 0)
              dp[i][j][k] = inf;
            else
              upd(dp[i][j][k], dp[i - 1][m - np + 1][k - 1] +
                                   cnt[max(i + m - np + 1, i + 1)][i + j] +
                                   (m - np + 1 == 0 ? (d != a[i] - '0') : 0));
          } else {
            upd(dp[i][j][k], dp[i - 1][m - np + 1][k] +
                                 cnt[max(i + m - np + 1, i + 1)][i + j] +
                                 (m - np + 1 == 0 ? (d != a[i] - '0') : 0));
          }
        }
      }
    }
  for (int i = 0; i <= n - m + 1; i++) {
    int res = dp[n][0][i];
    if (res >= inf) res = -1;
    printf("%d%c", res, " \n"[i == n - m + 1]);
  }
}
