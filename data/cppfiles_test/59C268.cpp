#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (auto &x : a)
      for (auto &y : x) cin >> y;
    bool flag = false;
    for (int d1 = 0; d1 < 5; ++d1) {
      for (int d2 = 0; d2 < 5; ++d2) {
        if (d1 == d2) continue;
        int cnt1 = 0, cnt2 = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
          if (!a[i][d1] && !a[i][d2]) {
            good = false;
            break;
          }
          cnt1 += a[i][d1];
          cnt2 += a[i][d2];
        }
        if (good && cnt1 >= n / 2 && cnt2 >= n / 2) {
          flag = true;
        }
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
