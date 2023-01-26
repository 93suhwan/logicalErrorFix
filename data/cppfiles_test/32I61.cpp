#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
const int inf = INT_MAX;
const int mod = 998244353;
int N, res;
long long sum[mx], a[mx], dp[600][mx];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Tc;
  for (cin >> Tc; Tc--;) {
    cin >> N;
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    dp[1][N] = 0;
    for (int i = N - 1; i >= 0; i--) dp[1][i] = max(dp[1][i + 1], a[i]);
    res = 1;
    for (int k = 2; k < 600; k++) {
      long long m = sum[k - 1];
      for (int i = 0; i < N; i++) {
        if (i + k <= N && m < dp[k - 1][i + 1])
          dp[k][i] = m;
        else
          dp[k][i] = 0;
        m -= a[i];
        m += a[i + k];
      }
      dp[k][N] = 0;
      for (int i = N - 1; i >= 0; i--) dp[k][i] = max(dp[k][i], dp[k][i + 1]);
      if (dp[k][0] == 0) {
        res = k - 1;
        break;
      }
    }
    cout << res << '\n';
  }
}
