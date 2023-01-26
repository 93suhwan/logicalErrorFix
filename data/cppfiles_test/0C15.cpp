#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
  for (int i = 0; i < min((int)a.size(), (int)b.size()); ++i) {
    if (a[i] != b[i]) {
      if (i % 2 == 0 && a[i] < b[i]) return true;
      if (i % 2 && a[i] > b[i]) return true;
      return false;
    }
  }
  return false;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<pair<string, int>> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i].first = a[i];
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  sort(a.begin(), a.end(), cmp);
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(b.begin(), b.end(), make_pair(a[i], -1)) - b.begin();
    if (idx < 0 || idx >= (int)b.size()) {
      cout << "-1\n";
      return;
    }
    ans[i] = b[idx].second + 1;
  }
  for (auto x : ans) cout << x << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
