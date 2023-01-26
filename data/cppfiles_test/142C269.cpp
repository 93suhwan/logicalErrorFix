#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    vector<int> v(n, 0), d;
    for (int i = 0; i < m; i++) {
      int a[n];
      for (int j = 0; j < n; j++) {
        cin >> a[j];
        v[j] = max(v[j], a[j]);
      }
      sort(a, a + n);
      d.push_back(a[n - 2]);
    }
    sort(d.begin(), d.end());
    sort(v.begin(), v.end());
    int ans = min(d[d.size() - 1], v[0]);
    cout << ans << '\n';
  }
}
