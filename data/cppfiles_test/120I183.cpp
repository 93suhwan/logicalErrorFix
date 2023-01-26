#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> v;
  for (int i = 1; i <= 2 * 1e6 + 1; i *= 2) {
    v.push_back(i);
  }
  while (t--) {
    int l, r;
    cin >> l >> r;
    int best = INT_MAX;
    for (auto x : v) {
      if (x > r) break;
      int ans = 0;
      int q = 0;
      q = (r - l + 1) / x;
      if (q < 2) q = 0;
      for (int i = l + q * x; i <= r; ++i) {
        if ((x & i) == 0) {
          ans++;
        }
      }
      q = (q * x) / 2;
      ans += q;
      best = min(ans, best);
    }
    cout << best << endl;
  }
  return 0;
}
