#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const long double eps = 1e-20;
const long long HASH = 131;
using namespace std;
long long a[maxn];
signed main() {
  std::ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if ((a & 1)) {
      long long tmp = b % 4;
      if (tmp == 1) {
        cout << a + b << endl;
      } else if (tmp == 2) {
        cout << a - 1 << endl;
      } else if (tmp == 3) {
        cout << a - 1 - b << endl;
      } else
        cout << a << endl;
    } else {
      long long tmp = b % 4;
      if (tmp == 1) {
        cout << a - b << endl;
      } else if (tmp == 2) {
        cout << a + 1 << endl;
      } else if (tmp == 3) {
        cout << a + 1 + b << endl;
      } else
        cout << a << endl;
    }
  }
  return 0;
}
