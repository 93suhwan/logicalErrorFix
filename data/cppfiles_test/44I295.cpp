#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    int a = abs(c - d);
    if (c == d) {
      cout << "1" << endl;
    } else if (a % 2 != 0) {
      cout << "-1" << endl;
    } else {
      cout << "2" << endl;
    }
  }
  return 0;
}
