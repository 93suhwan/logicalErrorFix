#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    vector<vector<int> > a(4);
    for (auto &it : a) {
      int k;
      cin >> k;
      it = vector<int>(k);
      for (int i = 0; i < k; i++) {
        cin >> it[i];
      }
    }
    int ans = INT_MIN;
    int temp = a[0][a[0].size() - 1] - a[0][0];
    ans = max(ans, temp * h);
    ans = max(ans, temp * (a[2][a[2].size() - 1]));
    ans = max(ans, temp * (a[3][a[3].size() - 1]));
    temp = a[1][a[1].size() - 1] - a[1][0];
    ans = max(ans, temp * h);
    ans = max(ans, temp * (h - a[2][0]));
    ans = max(ans, temp * (h - a[3][0]));
    temp = a[2][a[2].size() - 1] - a[2][0];
    ans = max(ans, temp * w);
    ans = max(ans, temp * (a[0][a[0].size() - 1]));
    ans = max(ans, temp * (a[1][a[1].size() - 1]));
    temp = a[3][a[3].size() - 1] - a[3][0];
    ans = max(ans, temp * w);
    ans = max(ans, temp * (w - a[0][0]));
    ans = max(ans, temp * (w - a[1][0]));
    cout << ans << endl;
  }
  return 0;
}
