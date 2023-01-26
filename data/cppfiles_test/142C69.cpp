#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> p(m, vector<int>(n));
  for (vector<int> &x : p) {
    for (int &y : x) cin >> y;
  }
  auto possible = [&](int x) -> bool {
    vector<int> ok(n, false);
    bool two = false;
    for (vector<int> s : p) {
      int row = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] >= x) {
          ok[i] = true;
          row++;
        }
      }
      if (row >= 2) two = true;
    }
    return two && all_of(ok.begin(), ok.end(), [](bool x) { return x; });
  };
  int low = 1, high = 1e9, mid;
  while (low <= high) {
    mid = (high - low) / 2 + low;
    if (possible(mid)) {
      if (!possible(mid + 1)) {
        cout << mid << '\n';
        return;
      } else
        low = mid + 1;
    } else
      high = mid - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
