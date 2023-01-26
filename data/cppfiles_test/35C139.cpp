#include <bits/stdc++.h>
using namespace std;
int t, m, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int res = 0;
    m++;
    for (int k = 30; k >= 0 & n < m; k--) {
      if (!(n & (1 << k)) && (m & (1 << k))) {
        res += (1 << k);
        n += (1 << k);
      }
    }
    cout << res << endl;
  }
  return 0;
}
