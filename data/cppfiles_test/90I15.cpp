#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x <= y)
      cout << (x + y) / 2 << '\n';
    else
      cout << x + y << '\n';
  }
  return 0;
}
