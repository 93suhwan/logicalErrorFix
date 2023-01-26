#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = (int)0x3f3f3f3f3f3f3f3f, ninf = (int)0xc0c0c0c0c0c0c0c0;
using ll = long long;
using ld = long double;
void solve() {
  const int N = (int)5e5 + 3;
  int q;
  cin >> q;
  vector<vector<int> > color(N);
  int id = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      color[x].push_back(++id);
    } else {
      int x, y;
      cin >> x >> y;
      if (x == y) continue;
      if (((int)(color[y]).size()) < ((int)(color[x]).size()))
        swap(color[x], color[y]);
      color[y].insert(color[y].end(), color[x].begin(), color[x].end());
      color[x].clear();
    }
  }
  vector<int> ans(N);
  for (int i = 1; i <= N; ++i) {
    for (auto& x : color[i]) {
      ans[x] = i;
    }
  }
  for (int i = 1; i <= id; ++i) cout << ans[i] << ' ';
  cout << '\n';
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
