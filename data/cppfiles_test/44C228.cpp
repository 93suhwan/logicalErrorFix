#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, a, c, d, b;
  cin >> t;
  for (int p = 0; p < t; p++) {
    cin >> c >> d;
    if (c == d) {
      if (c == 0) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    } else if ((c == 0 && d != 0) || (c != 0 && d == 0)) {
      if (c % 2 != 0 || d % 2 != 0) {
        cout << -1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      if ((c + d) % 2 == 0) {
        cout << 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
