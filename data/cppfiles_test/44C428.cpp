#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b) {
      if (a == 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else {
      if (abs(a - b) % 2)
        cout << -1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
