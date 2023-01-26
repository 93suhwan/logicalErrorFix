#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long LOG = 18;
const long long INF = 1e9 + 7;
template <class X, class Y>
bool minimize(X &x, const Y &y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
long long dx[]{-1, 1, 0, 0};
long long dy[]{0, 0, 1, -1};
long long a[2005], n, k, dp[2005][2005];
void read() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
}
void solve() {
  memset(dp, 0, sizeof dp);
  for (long long i = 0; i < n; i++) {
    for (long long num_delete = 0; num_delete <= i; num_delete++) {
      maximize(dp[i + 1][num_delete],
               dp[i][num_delete] + (a[i + 1] == i + 1 - num_delete));
      maximize(dp[i + 1][num_delete + 1], dp[i][num_delete]);
    }
  }
  long long result = INF;
  for (long long num_delete = 0; num_delete <= n; num_delete++) {
    if (dp[n][num_delete] >= k) {
      cout << num_delete << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long num_test = 1;
  cin >> num_test;
  while (num_test--) {
    read();
    solve();
  }
}
