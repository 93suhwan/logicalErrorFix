#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c1, c2;
    cin >> n;
    int x, y;
    x = n / 3;
    y = n % 3;
    if (y == 1) {
      c1 = x + 1;
      c2 = x;
    } else if (y == 2) {
      c1 = x;
      c2 = x + 1;
    } else {
      c1 = x;
      c2 = x;
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
