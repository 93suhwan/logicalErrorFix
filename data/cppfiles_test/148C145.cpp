#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, s, d, w, h, t, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> w >> h;
    for (int j = 1; j <= 4; j++) {
      cin >> m;
      for (int i = 1; i <= m; i++) {
        cin >> d;
        if (i == 1) a = d;
        if (i == m) b = d;
      }
      if (j == 1 or j == 2) {
        ans = max(ans, (b - a) * h);
      }
      if (j == 3 or j == 4) {
        ans = max(ans, (b - a) * w);
      }
    }
    cout << ans << '\n';
    ans = 0;
  }
}
