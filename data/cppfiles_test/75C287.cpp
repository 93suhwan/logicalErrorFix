#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    vector<pair<long long, int>> v;
    for (int i = 0; i < n; i++) {
      cin >> k;
      long long mx = 0, temp;
      for (int j = 0; j < k; j++) {
        cin >> temp;
        mx = max(mx, temp - j + 1);
      }
      v.push_back({mx, k});
    }
    sort(v.begin(), v.end());
    long long ans = v[n - 1].first;
    for (int i = n - 2; i >= 0; i--) {
      ans = max({ans - v[i].second, v[i].first, 0LL});
    }
    cout << ans << endl;
  }
  return 0;
}
