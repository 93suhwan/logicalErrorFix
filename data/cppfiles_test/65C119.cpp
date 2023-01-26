#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 998244353;
inline int add(int x, int y) { return (x + y >= mod ? x + y - mod : x + y); }
inline int sub(int x, int y) { return (x - y < 0 ? x - y + mod : x - y); }
inline int gun(int x, int y) { return ((x * 1ll * y) % mod); }
int n, m;
pair<int, int> a[55];
int g[N];
int dp[N][55];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int now = 1; now <= m; now++) {
    int sum = m / now;
    for (int idx = n; idx >= 0; idx--) {
      int l = (a[idx].first + now - 1) / now;
      int r = a[idx].second / now;
      for (int cur = 0; cur <= sum; cur++) {
        if (idx == n) {
          dp[cur][idx] = 1;
          continue;
        }
        int ans = 0;
        if (l <= r && cur + l <= sum) {
          int ses = min(cur + r, sum);
          ans = dp[ses][idx + 1];
          if (cur + l - 1 >= 0) ans = sub(ans, dp[cur + l - 1][idx + 1]);
        }
        dp[cur][idx] = ans;
      }
      for (int cur = 1; cur <= sum; cur++) {
        dp[cur][idx] = add(dp[cur][idx], dp[cur - 1][idx]);
      }
    }
    g[now] = dp[0][0];
    ;
  }
  for (int i = m; i >= 1; i--) {
    for (int j = i + i; j <= m; j += i) {
      g[i] = sub(g[i], g[j]);
    }
  }
  cout << g[1] << "\n";
  return 0;
}
