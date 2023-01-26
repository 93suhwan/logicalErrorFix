#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, a[N], b[N], m[N], x[N], y[N];
void solve() {
  cin >> n;
  vector<pair<int, int>> ve;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i] >> b[i] >> m[i];
    ve.push_back({a[i] + b[i] - m[i], i});
  }
  sort(begin(ve), end(ve));
  int ans = 0;
  for (int i = 0; i < (int)(ve).size();) {
    int cnt = 0;
    vector<pair<pair<int, int>, int>> ve2;
    while (i < n && ve[i].first == ve[i - cnt].first) {
      int pos = ve[i].second;
      int l = max(0, a[pos] - m[pos]), r = a[pos] - max(0, m[pos] - b[pos]);
      ve2.push_back({{l, r}, pos});
      ++i, ++cnt;
    }
    sort(begin(ve2), end(ve2));
    pair<int, int> I = {-inf, inf};
    int pre = -1;
    for (int j = 0; j < ((int)(ve2).size()); ++j) {
      int l = ve2[j].first.first, r = ve2[j].first.second;
      if (l > I.second) {
        int target = I.second;
        ++ans;
        for (int k = pre + 1; k < (j); ++k) {
          int pos = ve2[k].second;
          x[pos] = a[pos] - target;
          y[pos] = m[pos] - x[pos];
        }
        pre = j - 1;
        I = {-inf, inf};
        --j;
      } else {
        I.first = max(I.first, l);
        I.second = min(I.second, r);
      }
    }
    int target = I.second;
    ++ans;
    for (int k = pre + 1; k < ((int)(ve2).size()); ++k) {
      int pos = ve2[k].second;
      x[pos] = a[pos] - target;
      y[pos] = m[pos] - x[pos];
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < (n); ++i) {
    cout << x[i] << ' ' << y[i] << '\n';
  }
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
