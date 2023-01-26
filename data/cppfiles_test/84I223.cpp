#include <bits/stdc++.h>
using namespace std;
long long r[1234567], q[1234567], qr[1002][1002], rq[1002][1002];
long long rr[1002][1002], qq[1002][1002];
int main() {
  long long a, b = 0, c = 0, d = 1, e = 1, f = 123456789, g = 0, h = 1;
  long long i[1234567], j[1234567], k = 1, l = 0;
  long long t = 0, z, x = 1, y, w, v = 0, u = 1234, gcd, lcm, mod = 1e9 + 7;
  char gg, ff, kk;
  string m[1234567], n = "", o, s, ss, nn = "", oo, mm[1234567];
  map<long long, long long> aa;
  cin >> a;
  for (b = 1; b <= a; b++) {
    cin >> c >> d;
    g = c / 2;
    if (c % 2 == 0) {
      g--;
    }
    c -= g;
    if (c > 1) {
      d -= d % 2;
    }
    cout << d / c << endl;
  }
}
