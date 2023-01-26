#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, t, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  t = 1;
  while (t--) {
    vector<bool> vis(550, 0);
    using vb = vector<bool>;
    vis[0] = 1;
    cin >> n;
    vector<vb> v(n);
    vector<int> r;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      auto vist(vis);
      for (int j = 0; j < x; j++) {
        if (vis[j]) vist[j ^ x] = vist[j] = 1;
      }
      vis = vist;
    }
    cout << count(vis.begin(), vis.end(), 1) << "\n";
    for (int i = 0; i < 512; i++) {
      if (vis[i]) cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
