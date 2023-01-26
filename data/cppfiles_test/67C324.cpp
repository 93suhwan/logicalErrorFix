#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    int mid = a - b + 1;
    int sub = a - b;
    int num1 = a - b - 1;
    if (2 * sub < a) {
      cout << -1 << endl;
      continue;
    }
    int num2 = 2 * sub - a + b - 1;
    if (c > 2 * sub || (num1 != num2))
      cout << -1 << endl;
    else {
      if (c >= mid)
        cout << c - (a - b) << endl;
      else
        cout << c + (a - b) << endl;
    }
  }
  return 0;
}
