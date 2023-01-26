#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long x = ceil((double)sqrt(k));
    long long y = sqrt(k);
    y *= y;
    if (k - y == 0)
      cout << x << " " << 1 << "\n";
    else if (k - y <= x)
      cout << k - y << " " << x << "\n";
    else {
      long long a = x * x;
      cout << x << " " << a - k + 1 << "\n";
    }
  }
}
