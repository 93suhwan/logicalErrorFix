#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  map<int, int> mp;
  int x, y;
  for (int i = 0; i <= k - 1; i++) {
    cin >> x >> y;
    mp[x] = y;
    mp[y] = x;
  }
  vector<int> tbp;
  for (int i = 1; i <= 2 * n; i++) {
    if (mp[i] == 0) {
      tbp.push_back(i);
      if (tbp.size() > (n - k)) {
        mp[tbp.back()] = tbp[tbp.size() - 1 - (n - k)];
        mp[tbp[tbp.size() - 1 - (n - k)]] = tbp.back();
      }
    }
  }
  vector<int> v;
  vector<int> vis(201, 0);
  for (int i = 1; i <= 2 * n; i++) {
    if (vis[i] == 1) continue;
    vis[i] = 1;
    vis[mp[i]] = 1;
    v.push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j <= i - 1; j++) {
      int p1 = v[i], p2 = mp[v[i]];
      int c1 = v[j], c2 = mp[v[j]];
      if ((c1 > p1 && c1 < p2) && (c2 > p1 && c2 < p2)) continue;
      if (!(c1 > p1 && c1 < p2) && !(c2 > p1 && c2 < p2)) continue;
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
