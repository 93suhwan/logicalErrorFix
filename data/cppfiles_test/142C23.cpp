#include <bits/stdc++.h>
using namespace std;
int m, n;
bool works(int mid, vector<vector<int>> ar) {
  vector<int> shops(m, 0);
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 0; j < m; j++) {
      if (ar[j][i] >= mid) {
        shops[j] += 1;
        ok = 1;
      }
    }
    if (!ok) {
      return false;
    }
  }
  for (int i = 0; i < m; i++) {
    if (shops[i] > 1) {
      return true;
    }
  }
  return false;
}
void solve() {
  cin >> m >> n;
  vector<vector<int>> ar(m, vector<int>(n));
  int mx = 0, mn = 1e9;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ar[i][j];
      mn = min(ar[i][j], mn);
      mx = max(ar[i][j], mx);
    }
  }
  while (mn < mx) {
    int mid = (mn + mx + 1) / 2;
    if (works(mid, ar)) {
      mn = mid;
    } else {
      mx = mid - 1;
    }
  }
  cout << mn << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
