#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, k;
int a[N];
int dp[N][N];
int answer;
void readInput() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  answer = 1e9;
}
int cal(int i, int j) {
  if (j > n) return -1e9;
  if (i > n) {
    return 0;
  }
  int &ret = dp[i][j];
  if (ret != (int)-1e9) return ret;
  ret = max(cal(i + 1, j) + (a[i] == i - j), cal(i + 1, j + 1));
  cout << i << ' ' << j << ' ' << ret << endl;
  return ret;
}
void solve() {
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= n + 1; ++j) dp[i][j] = -1e9;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = max(dp[i - 1][j] + (a[i] == i - j), dp[i - 1][j - 1]);
      if (dp[i][j] >= k) answer = min(answer, j);
    }
  }
  if (answer > n) answer = -1;
  printf("%d\n", answer);
}
int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    readInput();
    solve();
  }
  return 0;
}
