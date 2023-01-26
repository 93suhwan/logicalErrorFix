#include <bits/stdc++.h>
using namespace std;
int numOfDigits(long long n) {
  int c = 0;
  while (n != 0) {
    c++;
    n = n / 10;
  }
  return c;
}
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    string s = to_string(n);
    long long res = 100, l = pow(10, 18);
    for (long long i = 1; i < l; i *= 2) {
      string d1 = to_string(i), d2 = to_string(n);
      int cfound = 0, p1 = 0, p2 = 0;
      while (p1 < d1.length() && p2 < d2.length()) {
        bool found = false;
        while (p2 != d2.length()) {
          if (d2[0] == d1[0]) {
            found = true;
            break;
          }
          d2 = d2.substr(1, d2.length() - 1);
        }
        if (found) {
          cfound++;
          d2 = d2.substr(1, d2.length() - 1);
          d1 = d1.substr(1, d1.length() - 1);
        }
      }
      res = min(res, (long long)numOfDigits(n) - (2 * cfound) + numOfDigits(i));
    }
    cout << res << endl;
  }
  return 0;
}
