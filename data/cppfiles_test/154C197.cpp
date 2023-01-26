#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || b + c == a || a + c == b || (a == c && b % 2 == 0) ||
        (b == c && a % 2 == 0) || (a == b && c % 2 == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
