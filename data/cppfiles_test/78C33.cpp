#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long l, r, a;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    a = r / 2 + 1;
    if (a >= l) {
      cout << r % a << '\n';
    } else {
      cout << r % l << '\n';
    }
  }
}
