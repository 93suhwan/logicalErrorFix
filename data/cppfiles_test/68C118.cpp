#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, r, c, d;
    cin >> k;
    double temp;
    temp = sqrt(k);
    if (temp != (int)temp) {
      d = pow((int)temp, 2);
      if ((d + 1 + (int)temp) >= k) {
        r = k - d;
        c = temp + 1;
      } else {
        c = pow(((int)temp + 1), 2) - k + 1;
        r = (int)temp + 1;
      }
    } else {
      r = temp;
      c = 1;
    }
    cout << r << ' ' << c << endl;
  }
}
