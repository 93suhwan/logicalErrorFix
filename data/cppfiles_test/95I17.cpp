#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<pair<int, int>> ve;
  vector<multiset<int>> msb(m), msr(m);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      cin >> a[i][j];
      if (j == 0) {
        ve.push_back({a[i][j], i});
      }
      msr[j].insert(a[i][j]);
    }
  }
  string ans(n, 'R');
  sort(begin(ve), end(ve));
  for (int i = 0; i < (int)(ve).size() - 1;) {
    int cnt = 0;
    while (i < (int)(ve).size() && ve[i].first == ve[i - cnt].first) {
      int r = ve[i].second;
      ans[r] = 'B';
      for (int j = 0; j < (m); ++j) {
        msr[j].erase(msr[j].find(a[r][j]));
        msb[j].insert(a[r][j]);
      }
      ++i, ++cnt;
    }
    if (i == (int)(ve).size()) {
      break;
    }
    int l = 0, r = 0;
    bool ok = 1;
    for (int j = 0; j < (m); ++j) {
      if (*prev(end(msb[j])) < *begin(msr[j])) {
        if (r) {
          ok = 0;
          break;
        }
        ++l;
      } else if (*prev(end(msr[j])) < *begin(msb[j])) {
        ++r;
      } else {
        ok = 0;
        break;
      }
    }
    if (ok && l > 0 && l < m) {
      cout << "YES\n" << ans << ' ' << l << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
