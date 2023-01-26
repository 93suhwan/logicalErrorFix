#include <bits/stdc++.h>
using namespace std;
int t;
long long l, r, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 1) {
      cout << n / 2 << " " << n / 2 + 1 << endl;
    } else if (n == 2) {
      cout << -1 << " " << 2 << endl;
    } else {
      int x = 3;
      while (n % x != 0) x += 2;
      cout << n / x - (n / x) / 2 << " " << n / x + (n / x) / 2 << endl;
    }
  }
  return 0;
}
