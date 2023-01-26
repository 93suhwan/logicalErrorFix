#include <bits/stdc++.h>
using namespace std;
int a, b, c;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> c;
    if (c % 2 == 1)
      cout << 2 << " " << c - 1 << '\n';
    else
      cout << 2 << ' ' << c << '\n';
  }
}
