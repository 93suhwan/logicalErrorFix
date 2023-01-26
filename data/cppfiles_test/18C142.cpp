#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, d, x, ans = 0, ones = 0;
  cin >> n >> d;
  vector<int> vis(n, -1);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!x) {
      vis[i] = 0;
      q.push(i);
    } else
      ones++;
  }
  for (; q.size(); q.pop()) {
    int curr = q.front();
    int nxt = (n - d + curr) % n;
    if (vis[nxt] >= 0) continue;
    vis[nxt] = vis[curr] + 1;
    ones--;
    ans = max(ans, vis[nxt]);
    q.push(nxt);
  }
  if (ones)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
