#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x <= y)
      cout << (x + y) / 2 << endl;
    else {
      long long res = x * y + y;
      cout << res << endl;
    }
  }
  return 0;
}
