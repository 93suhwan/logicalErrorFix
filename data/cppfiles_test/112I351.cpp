#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long test;
  cin >> test;
  long long a, b, c, m;
  while (test--) {
    cin >> a >> b >> c >> m;
    if (a + b + c - 3 < m) {
      cout << "NO\n";
      continue;
    }
    if (a + b + c - 3 == m) {
      cout << "YES\n";
      continue;
    }
    long long t = a + b + c - 3 - m;
    if (a + b + c - max({a, b, c}) >= t) cout << "YES\n";
  }
}
