#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    a %= 2;
    b %= 2;
    c %= 2;
    if ((a == 1 && (b == 1 && c == 1)) || (a == 0 && (b == 0 && c == 0))) {
      cout << 0 << endl;
    } else if (a == 0 && (b == 1 && c == 1)) {
      cout << 1 << endl;
    } else if (b == 0 && (a == 1 && c == 1)) {
      cout << 2 << endl;
    } else if (b == 0 && (a == 1 && c == 0)) {
      cout << 1 << endl;
    } else if (c == 0 && (b == 1 && a == 1)) {
      cout << 1 << endl;
    } else if (c == 0 && (b == 1 && a == 0)) {
      cout << 2 << endl;
    } else if (c == 1 && (b == 0 && a == 0)) {
      cout << 3 << endl;
    }
  }
  return 0;
}
