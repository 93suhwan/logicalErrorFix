#include <bits/stdc++.h>
using namespace std;
int f(int n, int k) {
  int r = n / k, s;
  if (r % 2) r--;
  r *= k;
  s = r / 2;
  r += k;
  s += max(0, n - r + 1);
  return s;
}
int main() {
  int t, l, r, i, p, m, a, b;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l == r)
      cout << 0 << "\n";
    else {
      p = 1;
      m = r - l;
      for (i = 0; i < 20; i++) {
        a = f(r, p);
        b = f(l - 1, p);
        if (a > b) m = min(m, r - l + 1 - (a - b));
        p *= 2;
      }
      cout << m << "\n";
    }
  }
}
