#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline long long read() {
  long long f = 1;
  long long x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
struct node {
  long long sum;
  int id;
  bool operator<(const node &x) const { return sum > x.sum; }
};
long long dp[maxn][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (long long i = 1; i <= n + 1; i++) {
      dp[i][0] = 0;
      dp[i][1] = 0;
    }
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      x++;
      dp[x][0] += dp[x][0] + dp[x - 1][0], dp[x][0] %= mod;
      dp[x][1] += dp[x][1], dp[x][1] %= mod;
      if (x >= 2) dp[x][1] += dp[x - 2][0], dp[x][1] %= mod;
      dp[x + 2][1] = dp[x + 2][1] * 2 % mod;
    }
    long long ans = 0;
    for (long long i = 1; i <= n + 1; i++) {
      ans += (dp[i][1] + dp[i][0]) % mod;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
