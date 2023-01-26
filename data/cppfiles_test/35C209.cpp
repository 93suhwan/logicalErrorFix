#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, ans = 0;
    cin >> n >> m;
    m += 1;
    for (int i = 30; i >= 0 && n < m; i--) {
      if ((n >> i & 1) == (m >> i & 1)) continue;
      if ((m >> i & 1)) {
        n |= 1 << i;
        ans |= 1 << i;
      }
    }
    cout << ans << endl;
  }
}
