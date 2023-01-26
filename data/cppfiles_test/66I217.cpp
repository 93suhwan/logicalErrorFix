#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, n, a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    n = b - a;
    if (c <= n)
      k = c + n;
    else
      k = c - n;
    if (k <= (n * 2) && a <= n && b > n && k != a && k != b)
      cout << k << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
