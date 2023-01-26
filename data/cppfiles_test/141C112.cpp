#include <bits/stdc++.h>
using namespace std;
int nrcifre(long long n) {
  int nrcif = 0;
  while (n != 0) {
    nrcif++;
    n /= 10;
  }
  return nrcif;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long a, s, b = 0, p = 1;
    cin >> a >> s;
    int ok = 1;
    long long copa = a, cops = s;
    while (s != 0 && ok == 1) {
      if (nrcifre(copa) > nrcifre(cops)) ok = 0;
      if (s % 100 - a % 10 <= 9 && s % 100 / 10 != 0) {
        b = b + (s % 100 - a % 10) * p;
        p *= 10;
        s /= 100;
        a /= 10;
      } else if ((s % 100 - a % 10 > 9 || s % 100 / 10 == 0) &&
                 s % 10 >= a % 10) {
        b += (s % 10 - a % 10) * p;
        p *= 10;
        s /= 10;
        a /= 10;
      } else if ((s % 100 - a % 10 > 9 || s % 100 / 10 == 0) &&
                 s % 10 < a % 10) {
        ok = 0;
      }
      copa = a;
      cops = s;
    }
    if (ok == 1)
      cout << b << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
