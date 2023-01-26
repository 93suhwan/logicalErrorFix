#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = abs(a - b);
    if (x < min(a, b))
      cout << -1 << endl;
    else {
      int y = min(a, b) - 1;
      int z = max(a, b) - y;
      int p = z + z - 2;
      if (c > p)
        cout << -1 << endl;
      else {
        if (c + x <= p)
          cout << c + x << endl;
        else if (c - x >= 1)
          cout << c - x << endl;
      }
    }
  }
  return 0;
}
