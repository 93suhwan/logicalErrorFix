#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> m >> n;
  map<int, vector<pair<int, int>>> matrix;
  vector<int> cnt(n, m), mag(m, n);
  int cnt2 = m;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      matrix[a].push_back(make_pair(j, i));
    }
  }
  int ans = -1;
  for (auto &elem : matrix) {
    ans = elem.first;
    bool ok = 1;
    for (auto &pr : elem.second) {
      int i = pr.first, j = pr.second;
      --cnt[i];
      --mag[j];
      if (cnt[i] == 0) {
        ok = 0;
        break;
      }
      if (mag[j] == 1) --cnt2;
    }
    if (!ok || cnt2 == 0) break;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
