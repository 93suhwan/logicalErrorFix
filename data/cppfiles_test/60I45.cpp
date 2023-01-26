#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    int ans = mx;
    for (int i = 0; i < n; i++) {
      ans = min(ans, mx & a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
