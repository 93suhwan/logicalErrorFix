#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int c, d;
    cin >> c >> d;
    int a = 0, b = 0;
    if (c == 0 && d == 0) {
      cout << 0 << endl;
      continue;
    }
    if (abs(c - d) == 0) {
      cout << 1 << endl;
      continue;
    }
    if (abs(c - d) % 2 == 0) {
      cout << 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
