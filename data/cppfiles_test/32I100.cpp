#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const int N1 = 450;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int a[N], dp[N][N1], pre[N];
int n;
int main() {
  fast();
  int t, z;
  cin >> t;
  for (int z = 1; z < t + 1; z++) {
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    int k = 0;
    while (k * (k + 1) / 2 <= n) k++;
    for (int j = 0; j < k + 1; j++) dp[n + 1][j] = -1000000000000000000;
    dp[n + 1][0] = 1000000000000000000;
    for (int i = n; i > 0; i--) {
      for (int j = 0; j <= k; j++) {
        dp[i][j] = dp[i + 1][j];
        if (j && i + j - 1 <= n &&
            pre[i + j - 1] - pre[i - 1] < dp[i + j][j - 1]) {
          dp[i][j] = max(dp[i][j], pre[i + j - 1] - pre[i - 1]);
        }
      }
    }
    for (int j = k; j >= 0; j--) {
      if (dp[1][j] > 0) {
        cout << j << "\n";
        break;
      }
    }
  }
}
