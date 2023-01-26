#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> val(n);
    int maxx = 0, pos = 0;
    for (int i = 0; i < n; i++) {
      cin >> val[i];
      if (maxx < val[i]) {
        pos = i;
        maxx = val[i];
      }
    }
    if (pos == n - 1) {
      long long ans = 1ll * val[n - 2] * maxx;
      cout << ans << endl;
    } else if (pos == 0) {
      long long ans = 1ll * val[1] * maxx;
      cout << ans << endl;
    } else {
      long long l, r;
      l = 1ll * val[pos - 1] * maxx;
      r = 1ll * val[pos + 1] * maxx;
      cout << max(l, r) << endl;
    }
  }
  return 0;
}
