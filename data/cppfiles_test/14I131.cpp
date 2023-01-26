#include <bits/stdc++.h>
using namespace std;
void processor() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int dp[2001][2001] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i + 1; j++) {
      if (i && dp[i - 1][j] > dp[i][j]) {
        dp[i][j] = dp[i - 1][j];
      }
      if (j != i + 1) {
        dp[i][j + 1] = dp[i][j] + (arr[i] == j + 1);
      }
    }
  }
  int out = -1;
  for (int i = n; i >= 0; i--) {
    if (dp[n - 1][i] >= k) {
      out = n - i;
      break;
    }
  }
  cout << out << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int count, counter = 0;
  cin >> count;
  while (counter++ < count) {
    processor();
  }
  return 0;
}
