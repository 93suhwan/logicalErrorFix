#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mx = 2e5 + 5;
ll dp[mx];
ll ind[mx];
ll seq[mx];
ll element[mx];
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string t = "abc";
  ll dp[6][n + 1];
  ll cur = 0;
  do {
    dp[cur][0] = 0;
    for (int i = 0; i < n; i++) {
      dp[cur][i + 1] = dp[cur][i] + (s[i] != t[i % 3]);
    }
    cur++;
  } while (next_permutation(t.begin(), t.end()));
  while (m--) {
    ll ans = n;
    ll l, r;
    cin >> l >> r;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, dp[i][r] - dp[i][l - 1]);
    }
    cout << ans << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
