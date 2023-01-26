#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y;
  long long n;
  cin >> t;
  while (t--) {
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
