#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 0 && (n - 1) % 4 == 0) {
      x += -n;
    } else if (x % 2 == 0 && (n - 2) % 4 == 0) {
      x += 1;
    } else if (x % 2 == 0 && (n - 3) % 4 == 0) {
      x += n + 1;
    } else if (x % 2 != 0 && (n - 1) % 4 == 0) {
      x -= -n;
    } else if (x % 2 != 0 && (n - 2) % 4 == 0) {
      x -= 1;
    } else if (x % 2 != 0 && (n - 3) % 4 == 0) {
      x -= n + 1;
    }
    cout << x << endl;
  }
  return 0;
}
