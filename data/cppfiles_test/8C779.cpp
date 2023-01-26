#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x, y;
    int r = n % 3;
    if (r < 2) {
      y = (n - r) / 3;
      x = y + r;
    }
    if (r == 2) {
      x = (n - r) / 3;
      y = x + 1;
    }
    cout << x << " " << y << endl;
  }
  return 0;
}
