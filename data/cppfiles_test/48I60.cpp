#include <bits/stdc++.h>
using namespace std;
const int64_t inf = LLONG_MAX / 2;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> a(n);
    for (int64_t i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int64_t nb = 0;
    for (int64_t i = 0; i < n; ++i) {
      if (a[i].second != i and a[a[i].second].second == i) ++nb;
    }
    nb /= 2;
    if (nb & 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
