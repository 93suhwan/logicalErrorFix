#include <bits/stdc++.h>
using namespace std;
long long t, l, r, m;
int main() {
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (r % 2 == 1) {
      m = r / 2;
      if (r - m >= l)
        cout << m;
      else {
        int n = r - m;
        int d = l - n;
        cout << m - d;
      }
    } else {
      m = r / 2 - 1;
      if (r - m >= l)
        cout << m;
      else
        cout << r - l;
    }
  }
}
