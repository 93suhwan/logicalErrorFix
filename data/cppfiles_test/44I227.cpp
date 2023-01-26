#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (abs(a - b) == 1)
      cout << -1 << endl;
    else if (a != b) {
      cout << 2 << endl;
    } else if (a == 0 && b == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
