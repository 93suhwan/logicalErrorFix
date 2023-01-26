#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e3 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int a[N];
int dp[N][N];
void main0() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = -INF;
      }
    }
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      a[i] = i - a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
      for (int j = 0; j <= i; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == j));
      }
    }
    int ans = -1;
    for (int j = 0; j <= n; ++j) {
      if (dp[n][j] >= k) {
        ans = j;
        break;
      }
    }
    cout << ans << endl;
  }
}
