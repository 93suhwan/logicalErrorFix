#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (b > a) {
      swap(a, b);
    }
    if ((b - a) % 2) {
      cout << -1 << "\n";
    } else if (a == b) {
      if (a == 0) {
        cout << 0 << "\n";
      } else {
        cout << 1 << "\n";
      }
    } else {
      cout << 2 << "\n";
    }
  }
  return 0;
}
