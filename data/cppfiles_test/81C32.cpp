#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end(), [&](pair<int, int> v1, pair<int, int> v2) {
    int mx1 = max(v1.first, v1.second);
    int mx2 = max(v2.first, v2.second);
    if (mx1 != mx2)
      return mx1 < mx2;
    else
      return v1.second < v2.second;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].second >= d) {
      ans++;
      d = max(d, v[i].first);
    }
  }
  cout << ans << '\n';
  return 0;
}
