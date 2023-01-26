#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
const long long maxN = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << "\n";
    } else if (l + 1 == r) {
      cout << 1 << "\n";
    } else {
      cout << (r + 1) / 2 - 1 << "\n";
    }
  }
}
