#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    int m = abs(a - b);
    if (a > 2 * m || b > 2 * m) {
      cout << "-1" << endl;
      continue;
    }
    if (c > 2 * m) {
      cout << "-1" << endl;
    } else if (c > m) {
      cout << c - m << endl;
    } else
      cout << c + m << endl;
  }
}
