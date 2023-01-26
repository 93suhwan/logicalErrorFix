#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 200010;
void sol() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> deg(n, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int j;
      cin >> j;
      --j;
      g[j].push_back(i);
      deg[i]++;
    }
  }
  set<int> s;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) s.insert(i);
  }
  int last = -1, ans = 1;
  for (int iter = 0; iter < n; ++iter) {
    if (s.empty()) {
      ans = -1;
      break;
    }
    auto it = s.lower_bound(last);
    if (it == s.end()) {
      ans++;
      it = s.begin();
    }
    int i = *it;
    s.erase(it);
    for (int j : g[i]) {
      --deg[j];
      if (deg[j] == 0) {
        s.insert(j);
      }
    }
    last = i;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int v_v = 1;
  cin >> v_v;
  while (v_v--) sol();
  return 0;
}
