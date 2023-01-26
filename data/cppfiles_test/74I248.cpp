#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if ((a == 0 && b == 1) || (b == 0) && a == 1) {
      cout << 2 << '\n';
      cout << 0 << " " << 1 << '\n';
    } else if (a == 1 && b == 1) {
      cout << 2 << '\n';
      cout << 0 << " " << 1 << '\n';
    } else if (a == 0 || b == 0) {
      long long xx = max(a, b);
      if (xx % 2) {
        cout << 2 << '\n';
        cout << xx / 2 << " " << (xx / 2) + 1 << '\n';
      } else {
        cout << 1 << '\n';
        cout << xx / 2 << '\n';
      }
    } else if (a == b) {
      cout << a + 1 << '\n';
      for (long long i = 0; i <= (a + b); i += 2) {
        cout << i << " ";
      }
      cout << '\n';
    } else if ((a - b) == 1 || (b - a) == 1) {
      cout << (a + b + 1) << '\n';
      for (long long i = 0; i <= (a + b); i++) {
        cout << i << " ";
      }
      cout << '\n';
    } else {
      cout << a + b << '\n';
      for (long long i = 1; i <= (a + b); i++) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
