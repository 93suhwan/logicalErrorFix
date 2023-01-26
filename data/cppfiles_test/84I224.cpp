#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int s, n;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    if (n == 1)
      cout << s;
    else if (s == 1) {
      cout << 0;
    } else {
      int x;
      if (n % 2 == 0)
        x = (s / ((n / 2) + 1));
      else
        x = (s / (round(n / (2 * 1.0))));
      cout << x;
    }
  }
  return 0;
}
