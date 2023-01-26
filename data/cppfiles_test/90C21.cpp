#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    int n = 0;
    if (x == y) {
      n = x;
    } else if (x > y) {
      n = x + y;
    } else {
      if (y % x == 0) {
        n = x;
      } else {
        x = y / x * x;
        n = (x + y) / 2;
      }
    }
    cout << n << '\n';
    assert(n % x == y % n);
  }
}
