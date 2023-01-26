#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ans = 0;
    for (int i = 29; i >= 0; i--) {
      if ((n >> i & 1) == 0 && ((m + 1) >> i & 1) == 1)
        ans += 1 << i;
      else if ((n >> i & 1) == 1 && ((m + 1) >> i & 1) == 0)
        break;
    }
    cout << ans << endl;
  }
  return 0;
}
