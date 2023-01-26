#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int it = 0;
    int ans = 1e9;
    while (it <= 1e3 + 501 && ans != 0) {
      it++;
      int mx = 0, mn = 1e9;
      for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
      }
      ans = min(ans, mx - mn);
      sort(a.begin(), a.end());
      a.back()--;
      a[0]++;
    }
    cout << ans << '\n';
  }
}
