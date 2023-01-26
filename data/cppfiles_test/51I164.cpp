#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, ctr = 0, x = 1, cnt;
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 2 * n;
    x = (long long)ceil((sqrt(1 + (4 * cnt)) - 1) / 2);
    if (n == 1)
      cout << 0 << ' ' << 1 << '\n';
    else
      cout << 1 << ' ' << x << endl;
  }
  return 0;
}
