#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int N, M, Q;
bool arr[1100][1100];
int dp[1100][1100][2], ans;
void upd(int x, int y, int d) {
  if (x < 1 || y < 1) return;
  if (arr[x][y]) return;
  if (d == 0) {
    ans -= dp[x][y][d];
    dp[x][y][d] = dp[x][y + 1][1 - d];
    if (!arr[x][y + 1]) dp[x][y][d]++;
    ans += dp[x][y][d];
    upd(x - 1, y, 1 - d);
  } else {
    ans -= dp[x][y][d];
    dp[x][y][d] = dp[x + 1][y][1 - d];
    if (!arr[x + 1][y]) dp[x][y][d]++;
    ans += dp[x][y][d];
    upd(x, y - 1, 1 - d);
  }
}
int main() {
  fastIO();
  cin >> N >> M >> Q;
  for (int i = N; i >= 1; i--) {
    for (int j = M; j >= 1; j--) {
      if (j + 1 <= M) dp[i][j][0] = dp[i][j + 1][1] + 1;
      if (i + 1 <= N) dp[i][j][1] = dp[i + 1][j][0] + 1;
    }
  }
  ans = N * M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ans += dp[i][j][0] + dp[i][j][1];
    }
  }
  for (int i = 1; i <= Q; i++) {
    int a, b;
    cin >> a >> b;
    if (arr[a][b] == false) {
      ans -= dp[a][b][0] + dp[a][b][1];
      dp[a][b][0] = 0;
      dp[a][b][1] = 0;
      ans--;
      arr[a][b] = true;
      upd(a, b - 1, 0);
      upd(a - 1, b, 1);
    } else {
      ans++;
      arr[a][b] = false;
      upd(a, b, 0);
      upd(a, b, 1);
    }
    cout << ans << "\n";
  }
}
