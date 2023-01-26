#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    for (int i = (0); i < (n); ++i) cin >> ar[i];
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      int pos = min_element(ar + i, ar + n) - (ar + i);
      if (pos != 0) {
        ans.push_back({i + 1, n, pos});
        rotate(ar + i, ar + i + pos, ar + n);
      }
    }
    cout << ans.size() << endl;
    for (int i = (0); i < (ans.size()); ++i) {
      cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2];
      cout << endl;
    }
  }
  return 0;
}
