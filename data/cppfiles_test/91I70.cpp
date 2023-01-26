#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main() {
  {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
  }
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (y == x) {
      cout << y;
    } else if (y < x)
      cout << x + y;
    else
      cout << y - y % x / 2;
    cout << '\n';
  }
}
