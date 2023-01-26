#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c, d, l, r, mem;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    l = abs(a - b);
    mem = l * 2;
    if (c > mem || l == 1) {
      cout << -1;
    } else {
      r = c - l;
      if (r <= 0) {
        d = c + l;
      } else {
        d = r;
      }
    }
    cout << d << endl;
  }
  return 0;
}
