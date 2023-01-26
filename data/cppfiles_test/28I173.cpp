#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    a = a % 2;
    b = b % 2;
    c = c % 2;
    if (c != 0) {
      cout << 3 - (a + 2 * b) << endl;
    } else {
      cout << abs(a - b * 2) << endl;
    }
  }
  return 0;
}
