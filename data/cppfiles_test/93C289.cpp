#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[200001], b, c, l, r, x, y;
int f(int n) {
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  if (n % 4 == 3) return 0;
  return n;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> b >> c;
    m = f(b - 1) ^ c;
    if (m > b)
      cout << b + 1 << endl;
    else if (m == b)
      cout << b + 2 << endl;
    else if (m == 0)
      cout << b << endl;
    else
      cout << b + 1 << endl;
  }
}
