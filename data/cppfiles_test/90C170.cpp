#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << endl;
    } else if (x == y) {
      cout << x << endl;
    } else {
      cout << y - ((x + y) / 2) % x << endl;
    }
  }
  return 0;
}
