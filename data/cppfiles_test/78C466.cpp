#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    long long a, b;
    cin >> l >> r;
    a = (r + 1) >> 1;
    b = (a << 1) - 1;
    if (a >= l && a <= r && b >= l && b <= r)
      cout << b - a << endl;
    else
      cout << r - l << endl;
  }
}
