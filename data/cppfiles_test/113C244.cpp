#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, c, b, d;
    cin >> a >> c >> b >> d;
    if (a == b and c == d) {
      cout << "=" << endl;
      continue;
    }
    long long l1 = 0, l2 = 0;
    long long t1 = a, t1t2 = b;
    for (; t1; l1++, t1 /= 10)
      ;
    for (; t1t2; l2++, t1t2 /= 10)
      ;
    if (l1 + c <= l2 + d) {
      if ((l1 + c) < (l2 + d)) {
        cout << "<" << endl;
        continue;
      }
    } else {
      cout << ">" << endl;
      continue;
    }
    if (c == d) {
      cout << (a > b ? ">" : "<") << endl;
      continue;
    }
    if (a == b) {
      cout << (c > d ? ">" : "<") << endl;
    }
    while (l1 < l2) {
      a *= 10;
      l1++;
    }
    while (l2 < l1) {
      b *= 10;
      l2++;
    }
    if (a < b) {
      cout << "<" << endl;
    } else {
      cout << (a > b ? ">" : "=") << endl;
    }
  }
}
