#include <bits/stdc++.h>
using namespace std;
const int N = 2007;
const int INF = 1e9 + 7;
int n, k;
int arr[N];
int nxt[N], cost[N];
int dp[N][N];
void solve() {
  cin >> n >> k;
  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i <= n; i++) {
    nxt[i] = -1;
    for (int j = i + 1; j <= n; j++) {
      if (arr[i] < arr[j]) {
        int need = arr[j] - arr[i] - 1;
        int have = j - i - 1;
        if (need <= have) {
          nxt[i] = j;
          cost[i] = have - need;
          break;
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      if (nxt[i] != -1) {
        dp[i][j] = cost[i] + dp[nxt[i]][j - 1];
      }
    }
  }
  int ans = dp[0][k];
  if (ans >= INF) ans = -1;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
