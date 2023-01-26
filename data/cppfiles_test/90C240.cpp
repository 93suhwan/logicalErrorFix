#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, t, val, a, b, val2;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a > b) {
      cout << a + b << "\n";
    } else if (a == b) {
      cout << a << "\n";
    } else {
      val = b / a;
      val2 = val * a + (b % a) / 2;
      cout << val2 << "\n";
    }
  }
  return 0;
}
