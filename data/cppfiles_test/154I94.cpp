#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || b + c == a || a + c == b)
      cout << "YES" << endl;
    else if ((a == b) && c % 2 == 0)
      cout << "YES" << endl;
    else if ((b == c) && a % 2 == 0)
      cout << "YES" << endl;
    else if ((c == a) && b % 2 == 0)
      cout << "YES" << endl;
    else if ((a == b) && c % 2 != 0)
      cout << "NO" << endl;
    else if ((b == c) && a % 2 != 0)
      cout << "NO" << endl;
    else if ((c == a) && b % 2 != 0)
      cout << "NO" << endl;
  }
}
