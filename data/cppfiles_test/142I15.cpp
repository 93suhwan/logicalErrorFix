#include <bits/stdc++.h>
#pragma GCC Optimize("0fast")
using namespace std;
bool cmp(int a, int b) { return a > b; }
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> v(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  int ans = 0, l = 0, h = INT_MAX;
  while (l <= h) {
    int mid = (l + h) / 2;
    set<int> shop;
    bool single = 1, multi = 0;
    for (int j = 0; j < n; j++) {
      single = 0;
      for (int i = 0; i < m; i++) {
        if (v[i][j] >= mid) {
          single = true;
          if (shop.count(i)) {
            multi = true;
            break;
          }
          shop.insert(i);
        }
      }
    }
    if (single && multi) {
      ans = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  };
  return 0;
}
