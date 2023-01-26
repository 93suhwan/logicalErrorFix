#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const int INF_32 = 0x3f3f3f3f;
const ll INF_64 = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const double PI = acos(-1);
ll n, a[10004];
ll dp[10004][2005];
void init() {
  ;
  ;
}
void solve(int icase) {
  ll maxv = -1;
  for (int i = 1; i <= n; i++) maxv = max(maxv, a[i]);
  for (int i = 0; i <= n; i++) fill(dp[i], dp[i] + 2 * maxv + 2, INF_64);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int l = 0; l <= 2 * maxv; l++) {
      if (dp[i][l] == INF_64) continue;
      dp[i + 1][max(0ll, l - a[i + 1])] =
          min(dp[i + 1][max(0ll, l - a[i + 1])], dp[i][l] + a[i + 1]);
      if (l + a[i] >= 2005) continue;
      dp[i + 1][l + a[i + 1]] =
          min(dp[i + 1][l + a[i + 1]], max(0ll, dp[i][l] - a[i + 1]));
    }
  }
  ll ans = INF_64;
  for (int i = 0; i <= 2 * maxv; i++) ans = min(ans, dp[n][i] + i);
  cout << ans << "\n";
}
int main() {
  int tcase = 1;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  cin >> tcase;
  for (int icase = 1; icase <= tcase; ++icase) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    init();
    solve(icase);
  }
  return 0;
}
