#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, c, d;
  cin >> t;
  while (t--) {
    cin >> c >> d;
    if (c == 0 && d == 0)
      cout << 0 << "\n";
    else if (c == d)
      cout << 1 << "\n";
    else if (abs(c - d) % 2 == 1)
      cout << -1 << "\n";
    else if (abs(c - d) % 2 == 0)
      cout << 2 << "\n";
  }
  return 0;
}
