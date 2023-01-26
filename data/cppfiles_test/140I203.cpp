#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int square = sqrt(x);
    int cube = cbrt(x);
    int m = cbrt(square);
    int n = sqrt(cube);
    if (m == n) {
      int y = cbrt(square);
      cout << y << endl;
      cout << cube + square - y << endl;
    } else {
      cout << square + cube - 1 << endl;
    }
  }
  return 0;
}
