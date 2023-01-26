#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a & 1)
      a = 1;
    else
      a = 0;
    if (b & 1)
      b = 1;
    else
      b = 0;
    if (c & 1)
      c = 1;
    else
      c = 0;
    if (a == 1 && b == 1 && c == 1)
      cout << 0 << endl;
    else if (a == 1 && b == 1 && c == 0)
      cout << 1 << endl;
    else if (a == 1 && b == 0 && c == 1)
      cout << 2 << endl;
    else if (a == 0 && b == 1 && c == 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
