#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0, low = 0, high = INT_MAX;
    while (low <= high) {
      int mid = (low + high) / 2;
      int cnt = 0;
      bool can = true, can1 = false;
      set<int> choosen;
      for (int j = 0; j < n; j++) {
        can = false;
        for (int i = 0; i < m; i++) {
          if (a[i][j] >= mid) {
            can = true;
            if (choosen.count(i)) {
              can1 = true;
            }
            choosen.insert(i);
          }
        }
        if (!can) {
          break;
        }
      }
      if (can && can1) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
