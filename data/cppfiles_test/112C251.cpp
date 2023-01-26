#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, m, p, x, y, z;
    cin >> a >> b >> c >> m;
    x = a;
    y = b;
    z = c;
    p = max({x - y - z, y - x - z, z - x - y});
    if (p < 0) {
      p = 0;
    }
    if (p > 0) {
      p--;
    }
    if (a - 1 + b - 1 + c - 1 >= m && p <= m) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
}
