#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
template <class T>
using V = vector<T>;
using vi = V<int>;
using pi = pair<int, int>;
int n, m;
V<V<ll>> p;
bool check(ll x) {
  vi vis(n);
  bool fg = false;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= x) {
        cnt++;
        vis[j] = 1;
      }
    }
    fg = fg || (cnt >= 2);
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += vis[i];
  return (sum == n && fg);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    p.clear();
    p.resize(m, V<ll>(n));
    for (auto& V : p)
      for (auto& u : V) cin >> u;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
      ll m = (l + r) / 2;
      if (check(m))
        l = m;
      else
        r = m;
    }
    cout << l << "\n";
  }
}
