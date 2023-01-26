#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> pool(8200, 0);
  pool[0] = 1;
  vector<vector<int>> has(n);
  vector<vector<int>> nxt(5005);
  for (int i = n - 1; i >= 0; i--) {
    nxt[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= 5000; i++) {
    if (nxt[i].size() != 0) {
      has[nxt[i].back()].emplace_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    nxt[a[i]].pop_back();
    for (auto x : has[i]) {
      if (pool[x]) continue;
      pool[x]++;
      for (int j = a[i] + 1; j <= 5000; j++) {
        if (nxt[j].size() != 0 && pool[j ^ x] == 0) {
          has[nxt[j].back()].emplace_back(j ^ x);
        }
      }
    }
  }
  vector<int> sol;
  for (int i = 0; i < 8200; i++)
    if (pool[i]) sol.emplace_back(i);
  cout << sol.size() << '\n';
  for (auto x : sol) cout << x << " ";
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}
