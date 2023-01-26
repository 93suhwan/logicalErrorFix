#include <bits/stdc++.h>
using namespace std;
signed main() {
  cout << fixed << setprecision(20);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long len = 2 * (n - 1);
    long long a, b;
    cin >> a >> b;
    string dda, ddb;
    cin >> dda >> ddb;
    long long br;
    long long rb;
    long long ap, bp;
    if (dda == "right")
      ap = a;
    else
      ap = len - a;
    if (ddb == "right")
      bp = b;
    else
      bp = len - b;
    br = (((ap - bp) % len) + len) % len;
    rb = len - br;
    if (br == 0 || rb == 1) {
      if (b == (n - 1)) {
        cout << 0 << endl;
      } else if (b == 0) {
        cout << n - 1 << endl;
      } else if (ddb == "left") {
        cout << n - 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      if (rb <= br) {
        bool nogsnijden = (dda == "right" && b >= a || dda == "left" && b <= a);
        if (dda == "right" ^ nogsnijden ^ (rb % 2 == 0)) {
          cout << n - 1 << endl;
        } else
          cout << 0 << endl;
      } else {
        bool nogsnijden = (ddb == "right" && a >= b || ddb == "left" && a <= b);
        if (ddb == "right" ^ nogsnijden ^ (br % 2 == 0)) {
          cout << 0 << endl;
        } else
          cout << n - 1 << endl;
      }
    }
  }
  return 0;
}
