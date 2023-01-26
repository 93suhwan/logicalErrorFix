#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int> > a;
    for (int i = 1; i <= n; i++) {
      cin >> k;
      int ma = 0;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        ma = max(ma, x - j + 2);
      }
      a.push_back({ma, k});
    }
    sort(a.begin(), a.end());
    int ans = a[0].first, cur = a[0].first + a[0].second;
    for (int i = 1; i < n; i++) {
      if (a[i].first > cur) ans += a[i].first - cur;
      cur += a[i].second;
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
