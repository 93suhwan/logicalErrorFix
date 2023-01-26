#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    if (y % x == 0) {
      cout << x << "\n";
      continue;
    }
    if (x > y) {
      cout << x + y << "\n";
      continue;
    }
    cout << y - ((y % x) / 2) << "\n";
  }
  return 0;
}
