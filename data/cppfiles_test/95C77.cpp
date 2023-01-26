#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
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
  for (int i = 0; i < (int)(ve).size();) {
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
    int l = 0, r = 0, mn = inf, mx = -inf;
    bool ok = 1;
    for (int j = 0; j < (m); ++j) {
      if (msb[j].empty() || msr[j].empty()) {
        ok = 0;
        break;
      }
      int mxb = *prev(end(msb[j])), mnb = *begin(msb[j]);
      int mxr = *prev(end(msr[j])), mnr = *begin(msr[j]);
      if (!r && max(mx, mxb) < min(mn, mnr)) {
        ++l;
        mx = max(mx, mxb);
        mn = min(mn, mnr);
      } else {
        if (!r) {
          mn = inf, mx = -inf;
        }
        if (max(mx, mxr) < min(mn, mnb)) {
          ++r;
          mx = max(mx, mxr);
          mn = min(mn, mnb);
        } else {
          ok = 0;
          break;
        }
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
