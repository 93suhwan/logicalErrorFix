#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (y < 2 * x)
      cout << y - x << endl;
    else
      cout << (y - 1) / 2 << endl;
  }
  return 0;
}
