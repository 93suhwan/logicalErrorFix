#include <bits/stdc++.h>
#pragma GCC push_options
#pragma GCC optimize("O0")
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
const int dx[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
const long long LINF = 1e18;
const double EPS = 1e-6;
const double PI = 3.14159;
const long long B = 31;
const long long LG = 20;
const long long INF = 1e9;
const long long M = 1e9 + 7;
const long long N = 1e5 + 9;
long long n;
long long a[N];
long long dp[N][500];
long long p[N];
int main() {
  ios_base::sync_with_stdio(false);
  int ts = 1;
  cin >> ts;
  while (ts--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) dp[n + 1][i] = -INF;
    dp[n + 1][0] = INF;
    long long k = sqrt(2 * n);
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j <= k; ++j) {
        dp[i][j] = dp[i + 1][j];
        if (p[i + j - 1] - p[i - 1] < dp[i + j][j - 1])
          dp[i][j] = max(dp[i][j], p[i + j - 1] - p[i - 1]);
      }
    }
    long long ans = 0;
    for (int i = 0; i <= k; ++i)
      if (dp[1][i] > 0) ans = i;
    cout << ans << '\n';
  }
}
