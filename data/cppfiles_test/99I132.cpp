#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 0 && n % 2 != 0) {
      x += (n - 1) / 2 - n;
    }
    if (x % 2 == 0 && n % 2 == 0) {
      x += n / 2;
    }
    if (x % 2 != 0 && n % 2 != 0) {
      x += -(n - 1) / 2 + n;
    }
    if (x % 2 != 0 && n % 2 == 0) {
      x += -n / 2;
    }
    cout << x << endl;
  }
  return 0;
}
