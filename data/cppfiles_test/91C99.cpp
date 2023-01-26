#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
double eps = 1e-6;
const long long mod = 998244353;
int t, n;
long long a[MAXN], dp[2][MAXN], ans;
int vis[MAXN];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mx = max((long long)mx, a[i]);
    }
    for (int i = 1; i <= mx; i++) dp[0][i] = dp[1][i] = 0;
    dp[n & 1][a[n]] = 1;
    for (int i = n - 1; i >= 1; i--) {
      int len = sqrt(a[i + 1]);
      for (int j = 1; j <= len; j++) {
        int v = a[i + 1] / j;
        if (!vis[v]) {
          vis[v] = 1;
          long long p = dp[(i + 1) & 1][v];
          long long k = a[i] / v + (a[i] % v == 0 ? 0 : 1);
          ans = (ans + (long long)i * p % mod * (k - 1) % mod) % mod;
          dp[i & 1][a[i] / k] += dp[(i + 1) & 1][v];
          dp[(i + 1) & 1][v] = 0;
        }
        if (!vis[j]) {
          vis[j] = 1;
          v = j;
          long long p = dp[(i + 1) & 1][v];
          long long k = a[i] / v + (a[i] % v == 0 ? 0 : 1);
          ans = (ans + (long long)i * p % mod * (k - 1) % mod) % mod;
          dp[i & 1][a[i] / k] += dp[(i + 1) & 1][v];
          dp[(i + 1) & 1][v] = 0;
        }
      }
      dp[i & 1][a[i]]++;
      for (int j = 1; j <= len; j++) vis[j] = vis[a[i + 1] / j] = 0;
    }
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}
