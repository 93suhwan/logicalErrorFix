#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    int a = 0, b = 0;
    if (c == 0 && d == 0) {
      cout << "0" << endl;
    } else if (c == d) {
      cout << "1" << endl;
    } else if (abs(c - d) > 1) {
      cout << "2" << endl;
    } else if (abs(c - d) == 1) {
      cout << "-1" << endl;
    }
  }
  return 0;
}
