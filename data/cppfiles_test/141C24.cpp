#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x = 1, b = 0, bs = 1;
    long long a, s;
    cin >> a >> s;
    while (s) {
      int p = s % 10, q = a % 10;
      s /= 10;
      a /= 10;
      if (p < q) {
        if ((s % 10) == 1) {
          s /= 10;
          p += 10;
        } else
          x = 0;
      }
      b += bs * (p - q);
      bs *= 10;
    }
    if (a) x = 0;
    if (!x)
      cout << -1 << endl;
    else
      cout << b << endl;
  }
}
