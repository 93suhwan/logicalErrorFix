#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    int x1 = a[i] % a[i - 1];
    if (find(a.begin(), a.end(), x1) == a.end()) {
      ans.push_back({a[i], a[i - 1]});
    }
  }
  for (int i = 0; i < n / 2; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
