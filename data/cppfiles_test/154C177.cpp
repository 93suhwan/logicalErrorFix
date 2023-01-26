#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int val = a;
    val = max(val, b);
    val = max(val, c);
    if (a == b && c % 2 == 0) {
      cout << "YES" << endl;
    } else if (a == c && b % 2 == 0) {
      cout << "YES" << endl;
    } else if (c == b && a % 2 == 0) {
      cout << "YES" << endl;
    } else {
      if (val == a && val - b == c) {
        cout << "YES" << endl;
      } else if (val == b && val - a == c) {
        cout << "YES" << endl;
      } else if (val == c && val - b == a) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
