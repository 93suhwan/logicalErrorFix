#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
const long long int INFF = 1e18;
const long long int M = 1e9 + 7;
long long int a[2005];
long long int n, k;
void solve(int test) {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (test == 37) {
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  vector<vector<long long int>> dp(n, vector<long long int>(n + 1, 0));
  dp[0][1] = (a[0] == 1);
  for (int i = 1; i < n; i++) {
    for (int numTaken = 1; numTaken <= i + 1; numTaken++) {
      dp[i][numTaken] = max(dp[i - 1][numTaken], (a[i] == numTaken ? 1 : 0) +
                                                     dp[i - 1][numTaken - 1]);
    }
  }
  for (int numTaken = n; numTaken > 0; numTaken--) {
    if (dp[n - 1][numTaken] >= k) {
      cout << n - numTaken << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  int tt = t;
  while (t--) {
    solve(tt - t);
  }
  return 0;
}
