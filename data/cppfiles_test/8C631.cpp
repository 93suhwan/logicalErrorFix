#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    bool m = true;
    bool p = true;
    long long n;
    cin >> n;
    int c1, c2, k = 0;
    while (m) {
      c1 = (2 * k + n) / 3;
      c2 = (n - k) / 3;
      if ((c1 + 2 * c2) == n) {
        break;
      } else if ((c2 + 2 * c1) == n) {
        cout << c2 << " " << c1 << "\n";
        p = false;
        break;
      } else
        k++;
    }
    if (p) cout << c1 << " " << c2 << "\n";
  }
  return 0;
}
