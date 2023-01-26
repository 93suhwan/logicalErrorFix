#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
const int INF = 1e9;
int dp[maxn][2];
int pre[maxn][2];
int p[maxn];
int a[maxn];
bool flag;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  if (flag) {
    cout << n << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = -INF;
  dp[0][1] = -INF;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 2; j++) {
      if (dp[i][j] != INF) {
        int x = j ? -p[i] : p[i];
        int y = dp[i][j];
        if (x < y) swap(x, y);
        for (int k = 0; k < 2; k++) {
          int z = k ? -p[i + 1] : p[i + 1];
          if (z > x) {
            if (dp[i + 1][k] > y) {
              dp[i + 1][k] = y;
              pre[i + 1][k] = j;
            }
          } else if (z > y) {
            if (dp[i + 1][k] > x) {
              dp[i + 1][k] = x;
              pre[i + 1][k] = j;
            }
          }
        }
      }
    }
  }
  for (int j = 0; j < 2; j++) {
    if (dp[n - 1][j] != INF) {
      for (int i = n - 1; i >= 0; i--) {
        a[i] = j ? -p[i] : p[i];
        j = pre[i][j];
      }
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  flag = (T == 20);
  while (T--) {
    solve();
  }
}
