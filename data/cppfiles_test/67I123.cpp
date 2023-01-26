#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    if (abs(a - b) == 2 && max(a, b) > 4)
      cout << -1 << endl;
    else if (max(a, b) == 2 && min(a, b) == 1) {
      if (c == 1)
        cout << 2 << endl;
      else if (c == 2)
        cout << 1 << endl;
    } else if (abs(a - b) == 1)
      cout << -1 << endl;
    else if (c <= 2 * abs(a - b)) {
      if (c >= (max(a, b) - min(a, b) + 1)) {
        cout << c - abs(a - b) << endl;
      } else
        cout << c + abs(a - b) << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
