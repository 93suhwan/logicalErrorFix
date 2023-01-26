#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == a + b || (a == b && !(c & 1)) ||
        (a == c && !(b & 1)) || (b == c && !(a & 1)))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
