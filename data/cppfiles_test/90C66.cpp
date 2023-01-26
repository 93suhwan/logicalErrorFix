#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long a[N];
long long n;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << endl;
    } else if (x == y) {
      cout << x << endl;
    } else {
      if (y % x == 0) {
        cout << x << endl;
        continue;
      }
      cout << y - (y % x) / 2 << endl;
    }
  }
  return 0;
}
