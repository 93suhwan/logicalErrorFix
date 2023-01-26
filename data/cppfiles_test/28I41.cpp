#include <bits/stdc++.h>
using namespace std;
long long abs1(long long x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    a %= 2;
    b %= 2;
    c %= 2;
    if (a == 0 && b == 0 && c == 0 || a == 1 && b == 1 && c == 1) {
      cout << 0 << endl;
    } else if (a == 0 && b == 0 && c == 1) {
      cout << 3 << endl;
    } else if (a == 0 && b == 1 && c == 0 || a == 1 && b == 0 && c == 1) {
      cout << 2 << endl;
    } else if (a == 0 && b == 1 && c == 1 || a == 1 && b == 0 && c == 0 ||
               a == 1 && b == 1 && c == 0) {
      cout << 1 << endl;
    }
  }
  return 0;
}
