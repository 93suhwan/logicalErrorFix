#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
const long long maxN = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << "\n";
    } else if (l + 1 == r) {
      if (l == 1) {
        cout << 0 << "\n";
      } else
        cout << 1 << "\n";
    } else if (l - 1 > r - l) {
      cout << r - l << "\n";
    } else {
      cout << (r - 1) / 2 << "\n";
    }
  }
}
