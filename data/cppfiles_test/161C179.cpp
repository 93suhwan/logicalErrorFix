#include <bits/stdc++.h>
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> arr(n);
  vector<vector<bool>> isThere(n + 1, vector<bool>(n + 1, false));
  for (ll i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    isThere[arr[i].first][arr[i].second] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = arr[i].first; j <= arr[i].second; j++) {
      if ((j == arr[i].first or isThere[arr[i].first][j - 1]) and
          (j == arr[i].second or isThere[j + 1][arr[i].second])) {
        cout << arr[i].first << " " << arr[i].second << " " << j << endl;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
