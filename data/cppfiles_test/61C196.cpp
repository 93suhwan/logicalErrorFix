#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> l(n), r(n);
  long long ans = n * (n - 1) * (n - 2) / 6;
  vector<pair<int, int>> e;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e.push_back({u, v});
    l[u]++, r[v]++;
  }
  for (auto [u, v] : e) {
    ans -= (l[u] - 1) * (r[v] - 1);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
