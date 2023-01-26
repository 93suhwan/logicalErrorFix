#include <bits/stdc++.h>
using namespace std;
long long const M = 1000000007;
double const pi = acos(-1);
long long const inf = 9e18;
long long const N = 10007;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long a, b;
    a = min(x, y);
    b = max(x, y);
    if (a == b) {
      if (a == 0)
        cout << 0 << "\n";
      else
        cout << 1 << "\n";
      continue;
    } else {
      if ((b - a) % 2 == 0)
        cout << 2 << "\n";
      else
        cout << -1 << "\n";
    }
  }
}
