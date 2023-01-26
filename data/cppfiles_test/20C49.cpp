#include <bits/stdc++.h>
using namespace std;
bool a[410][410];
int p1[410][410], p0[410][410];
int work(int l, int r, int y) {
  return p0[r - 1][y] - p0[l][y] + !a[l][y] + !a[r][y];
}
void run() {
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '1');
    }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      p0[i][j] = p0[i - 1][j] + a[i][j];
      p1[i][j] = p1[i - 1][j] + !a[i][j];
    }
  int ans = 1e9;
  for (int up = 1; up <= N; up++)
    for (int down = up + 4; down <= N; down++) {
      int dp = 1e9;
      for (int r = 3; r < M; r++) {
        dp = min(work(up, down, r) + work(up, down, r - 1) +
                     p1[down - 1][r - 2] - p1[up][r - 2],
                 dp + work(up, down, r));
        ans = min(ans, dp + p1[down - 1][r + 1] - p1[up][r + 1]);
      }
    }
  cout << ans << "\n";
}
int main(int argc, char **argv) {
  int T;
  cin >> T;
  while (T--) run();
}
