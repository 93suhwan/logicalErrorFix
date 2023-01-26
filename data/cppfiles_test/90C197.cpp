#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long x, y;
    cin >> x >> y;
    if (y % x == 0LL) {
      cout << x << "\n";
    } else if (x > y) {
      cout << x + y << "\n";
    } else {
      cout << (y / x) * x + (y - (y / x) * x) / 2 << "\n";
    }
  }
  return 0;
}
