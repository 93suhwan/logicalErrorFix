#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, x, mi = 100000, ma = 0, y;
    cin >> n;
    vector<pair<int, int>> v;
    set<int> s;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      v.push_back({a, b});
      mi = min(mi, min(a, b));
      ma = max(ma, max(a, b));
    }
    sort(v.begin(), v.end());
    for (int i = mi; i <= ma; i++) {
      s.insert(i);
    }
    for (int i = 0; i < n; i++) {
      x = v[i].first;
      y = v[i].second;
      auto it = lower_bound(s.begin(), s.end(), y);
      cout << y << " " << x << " " << *it << endl;
      s.erase(*it);
    }
  }
  return 0;
}
