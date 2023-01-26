#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }
    vector<int> v1(n), v2(n);
    v1[n - 1] = 0;
    v2[0] = 0;
    for (int i = n - 1; i > 0; i--) {
      v1[i - 1] = v1[i] + v[0][i];
    }
    for (int i = 1; i < n; i++) {
      v2[i] = v2[i - 1] + v[1][i - 1];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      ans = min(ans, max(v1[i], v2[i]));
    }
    cout << ans << endl;
  }
  return 0;
}
