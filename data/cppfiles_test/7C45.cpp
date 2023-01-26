#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAX = 505;
int dp[2][MAX][MAX], fail[MAX], ans[MAX], go[MAX][2];
void solve(int tc) {
  for (int e = 0; e < MAX; e++) {
    for (int p = 0; p < MAX; p++) {
      dp[0][e][p] = dp[1][e][p] = 1e9;
    }
  }
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  memset(fail, -1, sizeof(fail));
  memset(go, -1, sizeof(go));
  int j = -1;
  for (int e = 1; e < m; e++) {
    while (j != -1 && b[e] != b[j + 1]) j = fail[j];
    if (b[e] == b[j + 1]) fail[e] = ++j;
  }
  for (int e = 0; e < m; e++) {
    for (int p = 0; p < 2; p++) {
      int j = e - 1;
      while (j != -1 && char(p + '0') != b[j + 1]) j = fail[j];
      if (char(p + '0') == b[j + 1]) go[e][p] = ++j;
    }
  }
  dp[1][0][0] = 0;
  int len = (n - m + 1);
  for (int e = 0; e < n; e++) {
    int first = (e % 2);
    int lx = ((e + 1) % 2);
    for (int p = 0; p < m; p++) {
      for (int q = 0; q <= len; q++) {
        dp[first][p][q] = 1e9;
      }
    }
    for (int p = 0; p < m; p++) {
      for (int q = 0; q <= len; q++) {
        int lv = dp[lx][p][q];
        if (b[p] == a[e]) {
          if (p == (int)b.size() - 1) {
            dp[first][fail[p] + 1][q + 1] =
                min(dp[first][fail[p] + 1][q + 1], lv);
          } else {
            dp[first][p + 1][q] = min(dp[first][p + 1][q], lv);
          }
          dp[first][go[p][(a[e] - '0') ^ 1] + 1][q] =
              min(dp[first][go[p][(a[e] - '0') ^ 1] + 1][q], lv + 1);
        } else {
          if (p == (int)b.size() - 1) {
            dp[first][fail[p] + 1][q + 1] =
                min(dp[first][fail[p] + 1][q + 1], lv + 1);
          } else {
            dp[first][p + 1][q] = min(dp[first][p + 1][q], lv + 1);
          }
          dp[first][go[p][(a[e] - '0')] + 1][q] =
              min(dp[first][go[p][(a[e] - '0')] + 1][q], lv);
        }
      }
    }
  }
  for (int e = 0; e <= len; e++) ans[e] = 1e9;
  int rx = (n - 1) % 2;
  for (int e = 0; e < m; e++) {
    for (int p = 0; p <= len; p++) {
      ans[p] = min(ans[p], dp[rx][e][p]);
    }
  }
  for (int e = 0; e <= len; e++) {
    if (ans[e] == 1e9) ans[e] = -1;
    cout << ans[e] << " ";
  }
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}
