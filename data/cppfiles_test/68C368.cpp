#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long k, x = 1;
    cin >> k;
    for (int i = 1;; ++i) {
      if (k >= x && k <= x + i - 1) {
        cout << i << " " << i - (k - x) << '\n';
        break;
      }
      if (k <= x && k >= x - i + 1) {
        cout << i - (x - k) << " " << i << "\n";
        break;
      }
      x += 2 * i;
    }
  }
  return 0;
}
