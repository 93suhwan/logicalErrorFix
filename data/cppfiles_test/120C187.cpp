#include <bits/stdc++.h>
using namespace std;
long long a[32];
int main() {
  long long x, m, y, z, ct = 0, n, a, b, mx;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    mx = LLONG_MIN;
    a = a - 1;
    for (long long j = 2; j <= 1000000; j *= 2) {
      x = a % j;
      y = b % j;
      if (x < j / 2) {
        x += 1;
      } else {
        x = j - x - 1;
      }
      if (y < j / 2) {
        y += 1;
      } else {
        y = j - y - 1;
      }
      mx = max(mx, x - y);
    }
    cout << (b - a - mx) / 2 << '\n';
  }
  return 0;
}
