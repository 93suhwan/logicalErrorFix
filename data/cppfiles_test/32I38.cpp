#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 500;
int solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;
  reverse(A.begin(), A.end());
  vector<ll> acc(N + 1);
  for (int i = 0; i < (int)(N); i++) acc[i + 1] = acc[i] + A[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(M, 0));
  dp[0][0] = 1LL << 60;
  for (int i = 1; i < (int)(N + 1); i++) {
    for (int j = 1; j < (int)(M); j++) {
      if (i - j < 0) break;
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (dp[i - j][j - 1] > acc[i] - acc[i - j]) {
        dp[i][j] = max(dp[i][j], acc[i] - acc[i - j]);
      }
    }
  }
  for (int i = M - 1; i >= 0; i--)
    if (dp[N][i] > 0) return i;
  return 1;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << endl;
  }
  return 0;
}
