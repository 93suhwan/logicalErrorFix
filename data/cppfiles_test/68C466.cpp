#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t = 0;
  cin >> t;
  for (long int i = 0; i < t; i++) {
    long int k = 0, d = 0, r = 0, c = 0;
    cin >> k;
    d = sqrt(k);
    if (k - d * d <= d && k - d * d != 0) {
      r = k - d * d;
      c = d + 1;
      cout << r << " " << c << endl;
    } else if (k - d * d == 0) {
      r = d;
      c = 1;
      cout << r << " " << c << endl;
    } else {
      r = d + 1;
      c = (d + 1) * (d + 1) - k + 1;
      cout << r << " " << c << endl;
    }
  }
  return 0;
}
