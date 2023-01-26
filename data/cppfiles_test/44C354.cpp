#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (c % 2 != d % 2)
      cout << "-1\n";
    else if (c == 0 && d == 0)
      cout << "0\n";
    else if (c == d)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
