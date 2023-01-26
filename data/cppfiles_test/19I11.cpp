#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &_ : (a)) cin >> _;
  if (n == 1) {
    cout << a[0] << "\n";
    return;
  }
  queue<pair<int, int> > q;
  q.push({a[0], 0});
  int ans = 2e9;
  for (int i = 1; i < n; i++) {
    set<pair<int, int> > vis;
    while ((int)(q).size()) {
      auto [len, diff] = q.front();
      q.pop();
      if (len > 1200) continue;
      diff = min(diff, len - diff);
      if (diff >= a[i]) {
        vis.insert({len, diff - a[i]});
      } else {
        vis.insert({len + a[i] - diff, 0});
      }
      if (len - diff >= a[i]) {
        vis.insert({len, len - diff - a[i]});
      } else {
        vis.insert({diff + a[i], 0});
      }
    }
    if (i == n - 1) {
      for (auto &[a, b] : vis) ans = min(ans, a);
    } else {
      for (auto &[a, b] : vis) q.push({a, min(a - b, b)});
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    solve();
  }
  return 0;
}
