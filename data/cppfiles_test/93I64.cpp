#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int iterable = 0; iterable < t; iterable++) {
    int a, b;
    cin >> a >> b;
    int xOrRel = 0;
    if (a % 2 == 0) {
      if (a % 4 == 0) {
        xOrRel = 0;
      } else {
        xOrRel = 1;
      }
    } else {
      xOrRel = (a - 1) | ((a - 1) % 4);
    }
    int div = a - 1;
    if (xOrRel == b) {
      cout << a << '\n';
    } else {
      int rem = b ^ xOrRel;
      int comn = b & xOrRel;
      int adD = b - comn;
      int subTr = xOrRel - comn;
      int ans = (subTr | adD);
      if (ans == a) {
        cout << a + 2 << '\n';
      } else {
        cout << a + 1 << '\n';
      }
    }
  }
}
