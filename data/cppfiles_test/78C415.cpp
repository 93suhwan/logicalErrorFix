#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    if (r & 1) {
      cout << r % max((r + 1) / 2, l) << "\n";
    } else if (2 * l <= r)
      cout << r / 2 - 1 << "\n";
    else
      cout << r - l << "\n";
  }
  return 0;
}
