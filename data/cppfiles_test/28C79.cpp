#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int diff = 0;
    if (c % 2 == 0) {
      if (b % 2 == 0) {
        if (a % 2 == 0)
          diff = 0;
        else
          diff = 1;
      } else {
        if (a % 2 == 0)
          diff = 0;
        else
          diff = 1;
      }
    } else {
      if (b % 2 == 0) {
        if (a % 2 == 0)
          diff = 1;
        else
          diff = 0;
      } else {
        if (a % 2 == 0)
          diff = 1;
        else
          diff = 0;
      }
    }
    cout << diff << endl;
  }
  return 0;
}
