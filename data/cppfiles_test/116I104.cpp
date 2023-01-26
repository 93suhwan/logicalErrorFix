#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
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
bool vis[maxn];
long long a[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      x++;
      a[i] = x;
      dp[x][0] += dp[x][0] + dp[x - 1][0], dp[x][0] %= mod;
      dp[x][1] += dp[x][1], dp[x][1] %= mod;
      if (x >= 2) dp[x][1] += dp[x - 2][1], dp[x][1] %= mod;
      dp[x + 2][1] = dp[x + 2][1] * 2 % mod;
    }
    long long ans = 0;
    for (long long i = 1; i <= n + 1; i++) {
      ans += (dp[i][1] + dp[i][0]) % mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
