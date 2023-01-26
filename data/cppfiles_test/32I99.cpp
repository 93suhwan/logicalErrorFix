#include <bits/stdc++.h>
using namespace std;
const int ms = 1e5 + 10;
long long a[ms];
long long dp[ms][500];
long long hz[ms];
int main() {
  ios::sync_with_stdio(false);
  int i, j;
  int k;
  cin >> k;
  while (k--) {
    long long n;
    cin >> n;
    for (i = 1; i <= n + 10; i++) {
      for (j = 0; j <= 500; j++) dp[i][j] = 0;
    }
    for (i = 1; i <= n; i++) cin >> a[i];
    hz[n + 1] = 0;
    a[n + 1] = 0;
    for (i = n; i >= 1; i--) {
      hz[i] = hz[i + 1] + a[i];
    }
    dp[n][1] = a[n];
    for (i = n - 1; i >= 1; i--) {
      for (j = 1; j <= 500; j++) {
        dp[i][j] = dp[i + 1][j];
        if (i + j <= n + 1 && hz[i] - hz[i + j] < dp[i + j][j - 1])
          dp[i][j] = hz[i] - hz[j + i];
      }
    }
    for (i = 500; i >= 1; i--) {
      if (dp[1][i]) {
        cout << i << endl;
        break;
      }
    }
  }
}
