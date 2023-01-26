#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> b;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        b.push_back(x);
      }
      a.push_back(b);
      b.clear();
    }
    int first = 0, second = -1, mx = 0, idx, mx1 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (a[i][j] > a[i][first]) {
          second = first;
          first = j;
        } else if (second == -1 || a[i][second] < a[i][j])
          second = j;
      }
      if (a[i][second] > mx) {
        mx = a[i][second];
        idx = i;
      }
      first = 0;
      second = -1;
    }
    int ans = mx;
    for (int j = 0; j < n; j++) {
      if (a[idx][j] < mx) {
        for (int i = 0; i < m; i++) {
          if (a[i][j] > mx1) mx1 = a[i][j];
        }
        if (mx1 < ans) ans = mx1;
        mx1 = 0;
      }
    }
    cout << ans << "\n";
    a.clear();
  }
  return 0;
}
