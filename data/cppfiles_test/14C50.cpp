#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long a[n];
  vector<vector<long long>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort((v).begin(), (v).end());
  vector<vector<int>> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == v[i][0]) continue;
    int idx = v[i][1];
    long long num = v[i][0];
    ans.push_back({idx + 1, i + 1, 1});
    for (int j = idx; j < i; j++) {
      a[j] = a[j + 1];
    }
    a[i] = num;
    v.clear();
    for (int j = 0; j < n; j++) v.push_back({a[j], j});
    sort((v).begin(), (v).end());
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    for (auto y : x) cout << y << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
