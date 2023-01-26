#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int w, h;
    cin >> w >> h;
    long long ans = 0;
    for (int i = 0; i < 4; i++) {
      int d = 0;
      int k, x;
      cin >> k >> x;
      d -= x;
      for (int j = 1; j < k; j++) cin >> x;
      d += x;
      ans = max(ans, (long long)d * (i < 2 ? h : w));
    }
    cout << ans << '\n';
  }
}
