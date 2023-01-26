#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int x;
    if ((a - 1) % 4 == 0) {
      x = (a - 1);
    }
    if ((a - 1) % 4 == 1) {
      x = 1;
    }
    if ((a - 1) % 4 == 2) {
      x = a;
    }
    if ((a - 1) % 4 == 3) {
      x = 0;
    }
    if (b < x) {
      cout << (a + 1) << endl;
    } else if (b == x) {
      cout << a << endl;
    } else if ((x ^ a) == b) {
      cout << (a + 2) << endl;
    } else {
      cout << (a + 1) << endl;
    }
  }
  return 0;
}
