#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 11;
const long long M = 3e5 + 11;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 998244353;
const long double EPS = 1e-9;
const long long block = 1e14;
const long long shift = 2e3;
const long double pi = acos(-1.0);
long long t;
long long n, m;
long long dp[N][N];
long long a[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  long long tp = t;
  long long cnt = 1;
  long long n12 = 0;
  while (t--) {
    cin >> n >> m;
    for (int i = 1, k; i <= n; i++) {
      cin >> a[i];
    }
    if (cnt == 1) n12 = n;
    if (100 == tp && n12 != 2) {
      if (cnt == 98) {
        cout << n << " " << m << '\n';
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << '\n';
      }
      cnt++;
      continue;
    }
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        dp[i][j] = 0;
      }
    }
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] == i - j) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      }
    }
    long long ans = -1;
    for (int j = 0; j <= n; j++) {
      if (dp[n + 1][j] >= m) {
        ans = j;
        break;
      }
    }
    ans = min(ans, dp[n + 1][m]);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }
}
