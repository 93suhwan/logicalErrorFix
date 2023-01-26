#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; ++i) {
    if (a[i].first == a[i].second) {
      cout << a[i].first << " " << a[i].second << " " << a[i].second << endl;
    } else {
      cout << a[i].first << " " << a[i].second << " " << a[i + 1].second + 1
           << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
