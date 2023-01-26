#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, a, b, c, m, x;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> m;
    x = ((a > 1) ? a - 1 : 0) + ((b > 1) ? b - 1 : 0) + ((c > 1) ? c - 1 : 0);
    if (x < m) {
      cout << "NO" << endl;
      continue;
    }
    if (x == m) {
      cout << "Yes" << endl;
      continue;
    }
    int A, B, C;
    A = max(max(a, b), c);
    B = a + b + c - A - min(min(a, b), c);
    C = min(min(a, b), c);
    if (A - B - C - 1 > m)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
