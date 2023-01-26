#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, a, b, c, i, j, k;
  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c;
    if (c > a && c < b) {
      if (b % a == 0)
        cout << 2 * c << endl;
      else if (c % (b - a) == 0)
        cout << -1 << endl;
      else
        cout << (c - (b - a)) << endl;
    } else if (c < a && c > b) {
      if (a % b == 0)
        cout << 2 * c << endl;
      else if (c % (a - b) == 0)
        cout << -1 << endl;
      else
        cout << (c - (a - b)) << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
