#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    long long a = 0, b = 0;
    if (c == 0 && d == 0) {
      cout << "0" << endl;
    } else if (c == d) {
      cout << "1" << endl;
    } else if (abs(c - d) % 2 == 0) {
      cout << "2" << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
