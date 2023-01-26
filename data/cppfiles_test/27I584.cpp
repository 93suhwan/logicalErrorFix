#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, k;
  cin >> t;
  while (t--) {
    bool ok = false;
    cin >> n >> m >> k;
    if (n == 1 && m == 0 && k - 1 > 1) {
      ok = 1;
    } else if (n == 2 && m == 1 && k - 1 > 1) {
      ok = 1;
    } else if (n == 3 && ((m == 2 && k - 1 > 2) || (m == 3 && k - 1 > 1))) {
      ok = 1;
    } else if (m >= n - 1 && m <= (n * n - n) / 2 && k - 1 > 2) {
      ok = 1;
    } else if (k - 1 == 2 && m == (n * n - n) / 2) {
      ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
