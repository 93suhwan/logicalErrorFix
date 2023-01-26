#include <bits/stdc++.h>
#pragma GCC optimize("-ffloat-store")
using namespace std;
int T, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (long long cs = 1; cs <= T; cs++) {
    cin >> x >> y;
    if (x <= y) {
      int hs = y / x;
      int near = hs * x;
      cout << (near + y) / 2 << "\n";
    } else {
      cout << (x + y) << "\n";
    }
  }
}
