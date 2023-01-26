#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n), dp(n, 1e9);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (!a[i]) q.push(i), dp[i] = 0;
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    int nxt = (u + d) % n;
    if (dp[nxt] == 1e9) {
      dp[nxt] = dp[u] + 1;
      q.push(nxt);
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
  if (ans == 1e9) ans = -1;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
