#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n * m; i++) {
      a[i].second = -a[i].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      sort(a.begin() + (m * i), a.begin() + (m * i + m));
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < j; k++) {
          if (a[i * m + k].second > a[i * m + j].second) {
            ans++;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
