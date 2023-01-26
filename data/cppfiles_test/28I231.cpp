#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int u = 0; u < t; u++) {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    a = a % 2;
    b = b % 2;
    c = c % 2;
    if (a == 0 && b == 0 && c == 0)
      cout << 0 << endl;
    else if (a == 1 && b == 1 && c == 1)
      cout << 0 << endl;
    else if (b == 1 && c == 1)
      cout << 1 << endl;
    else if (b == 1 && a == 1)
      cout << 1 << endl;
    else if (a == 1)
      cout << 1 << endl;
    else if (c == 1) {
      if (a == 1)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
