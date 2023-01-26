#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    if (abs(a - b) == 2 && min(a, b) != 1) cout << -1 << endl;
    if (c >= 1 && c < 2 * (max(a, b) - min(a, b) + 1) && abs(a - b) != 1) {
      if (c >= (max(a, b) - min(a, b) + 1)) {
        cout << c - abs(a - b) << endl;
      } else
        cout << c + abs(a - b) << endl;
    } else if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
      if (c == 1)
        cout << 2 << endl;
      else if (c == 2)
        cout << 1 << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
