#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (9 > n)
      cout << 0 << '\n';
    else if (n == 9) {
      cout << 1 << endl;
    } else if (n > 9) {
      int d = n / 10;
      cout << d << endl;
    }
  }
  return 0;
}
