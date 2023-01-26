#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2 * 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    string second;
    cin >> second;
    int n = second.size();
    int dp[n + 1][2][2];
    memset(dp, 0, sizeof dp);
    dp[n][0][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int h1 = 0; h1 <= 9; h1++) {
        for (int h2 = 0; h2 <= 9; h2++) {
          for (int l = 0; l < 2; l++) {
            for (int r = 0; r < 2; r++) {
              if ((h1 + h2 + l) % 10 == (second[i] - '0'))
                dp[i][r][(h1 + h2 + l) / 10] += dp[i + 1][l][r];
            }
          }
        }
      }
    }
    cout << dp[0][0][0] - 2 << "\n";
  }
}
