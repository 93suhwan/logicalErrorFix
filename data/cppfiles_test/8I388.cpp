#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x = 0, y = 0, diff;
    int n;
    int min = n;
    diff = abs(x - y);
    cin >> n;
    int x1, y1;
    for (int i = 0; i < n; i++) {
      y = i;
      x = n - 2 * y;
      if (abs(x - y) < min) {
        min = abs(x - y);
        x1 = x;
        y1 = y;
      }
    }
    cout << x1 << " " << y1 << endl;
  }
  return 0;
}
