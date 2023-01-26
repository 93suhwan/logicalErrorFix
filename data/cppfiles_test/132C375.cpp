#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a[7];
    for (long long i = 0; i < 7; i++) cin >> a[i];
    long long x = a[0];
    long long y = a[1];
    long long z;
    if (a[2] == a[0] + a[1]) {
      z = a[3];
    } else {
      z = a[2];
    }
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}
