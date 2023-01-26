#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 2;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    if (x % (2 * 1ll))
      cout << x / (2 * 1ll) << " " << x / (2 * 1ll) + (1 * 1ll) << endl;
    else
      cout << -x + 1 << " " << x << endl;
  }
}
