#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int a = x / 3;
    if (a * 3 == x) {
      cout << a << ' ' << a << endl;
    } else if (a * 3 == (x - 1)) {
      cout << a + 1 << ' ' << a << endl;
    } else {
      cout << a << ' ' << a + 1 << endl;
    }
  }
  return 0;
}
