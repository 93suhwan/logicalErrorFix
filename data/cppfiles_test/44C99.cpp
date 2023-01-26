#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, a1, b1;
    cin >> a1 >> b1;
    a = max(a1, b1);
    b = min(a1, b1);
    if ((a - b) % 2 != 0) {
      cout << -1 << endl;
    } else {
      if (a == 0 and b == 0) {
        cout << 0 << endl;
      } else {
        if (a == b) {
          cout << 1 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    }
  }
}
