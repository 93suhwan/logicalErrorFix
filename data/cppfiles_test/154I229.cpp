#include <bits/stdc++.h>
using namespace std;
int main() {
  int no_test;
  cin >> no_test;
  while (no_test--) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = 6, gurthu;
    while (x--) {
      gurthu = 4;
      if (a + b <= c) {
        if (c - a == b) {
          gurthu = 4;
          break;
        } else
          gurthu = 2;
      } else if (a == c && b % 2 == 0)
        gurthu = 4;
      else
        gurthu = 2;
      a = a ^ b ^ c;
      b = a ^ b ^ c;
      c = a ^ b ^ c;
      a = a ^ b ^ c;
    }
    if (gurthu == 4)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
