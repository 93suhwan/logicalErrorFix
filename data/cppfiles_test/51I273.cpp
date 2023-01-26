#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, ctr = 0, x = 1, cnt;
  cin >> t;
  while (t--) {
    bool negative = false;
    cin >> n;
    if (n < 0) {
      negative = true;
      n *= -1;
    }
    cnt = 2 * n;
    x = (long long)ceil((sqrt(1 + (4 * cnt)) - 1) / 2);
    if (n == 1)
      cout << 0 << ' ' << 1 << '\n';
    else if (n == 2)
      cout << -1 << ' ' << 2 << '\n';
    else {
      if (!negative)
        cout << 1 << ' ' << x << '\n';
      else
        cout << -x << ' ' << 1 << '\n';
    }
  }
  return 0;
}
