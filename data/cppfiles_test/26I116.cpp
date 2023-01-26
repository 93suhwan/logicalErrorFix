#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const long long P = 1000000007;
long long dp[2 * N];
int main() {
  dp[3] = 3;
  for (long long i = 4; i <= 2 * (N - 10); ++i) dp[i] = (dp[i - 1] * i) % P;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    if (n == 2) cout << 12 << endl;
    cout << dp[2 * n] << endl;
  }
  return 0;
}
