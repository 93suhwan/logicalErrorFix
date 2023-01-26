#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (abs(a - b) % 2 != 0)
      cout << -1 << endl;
    else if (abs(a - b) % 2 == 0 and a - b == 0 and a != 0 and b != 0)
      cout << 1 << endl;
    else if (abs(a - b) % 2 == 0 and a - b == 0 and a == 0 and b == 0)
      cout << 0 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}
