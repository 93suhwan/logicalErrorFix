#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[200001];
int main() {
  cin >> n >> m;
  dp[2] = 2 % m;
  dp[3] = 5 % m;
  dp[4] = 12 % m;
  dp[5] = 25 % m;
  int sum = 44 % m;
  for (int i = 6; i <= n; i++) {
    dp[i] = sum;
    dp[i] = (dp[i] + (i + 1) / 2 + 1) % m;
    for (int j = 2; j <= i - 1; j++) {
      dp[i] += dp[i / j];
    }
    sum = (sum + dp[i]) % m;
  }
  cout << dp[n] << endl;
}
