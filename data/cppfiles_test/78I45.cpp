#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 0;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    long long a = 0, b = 0;
    cin >> a >> b;
    long long ans = 0;
    if (a <= (b / 2) + 1) {
      ans = b / 2;
    } else {
      ans = b - a;
    }
    cout << ans << endl;
  }
  return 0;
}
