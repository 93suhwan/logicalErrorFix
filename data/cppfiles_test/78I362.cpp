#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, i, j, n, t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
    } else if (abs(b - a) == 1) {
      cout << 1 << endl;
    } else if ((b % a) % 2 == 0) {
      cout << b - (b / 2) - 1 << endl;
    } else {
      cout << b - (b / 2) + 1 << endl;
    }
  }
}
