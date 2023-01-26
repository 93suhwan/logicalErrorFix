#include <bits/stdc++.h>
using namespace std;
const int MAXN = 502;
const int INF = 0x3F3F3F3F;
int dp[2][MAXN][MAXN];
int aut[MAXN][2], pi[MAXN];
bool a[MAXN], b[MAXN];
int n, m;
char ch;
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fast_io();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    a[i] = (ch - '0');
  }
  for (int i = 0; i < m; i++) {
    cin >> ch;
    b[i] = (ch - '0');
  }
  for (int i = 1; i < m; i++) {
    int at = pi[i - 1];
    while (at and b[at] != b[i]) at = pi[at - 1];
    at += (b[at] == b[i]);
    pi[i] = at;
  }
  for (int i = 0; i <= m; i++) {
    for (int c = 0; c < 2; c++) {
      if ((i and b[i] != c) or (i == m))
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + (b[i] == c);
    }
  }
  memset(dp, INF, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    bool at = (i & 1);
    memset(dp[at], INF, sizeof(dp[at]));
    for (int j = 0; j <= (n - m + 1); j++) {
      for (int k = 0; k <= m; k++) {
        if (dp[!at][j][k] >= INF) continue;
        int to = aut[k][a[i]];
        dp[at][j + (to == m)][to] =
            min(dp[at][j + (to == m)][to], dp[!at][j][k]);
        to = aut[k][!a[i]];
        dp[at][j + (to == m)][to] =
            min(dp[at][j + (to == m)][to], 1 + dp[!at][j][k]);
      }
    }
  }
  for (int i = 0; i <= (n - m + 1); i++) {
    int opt = INF;
    for (int j = 0; j <= m; j++) opt = min(opt, dp[n & 1][i][j]);
    printf("%d ", (opt != INF ? opt : -1));
  }
  return 0;
}
