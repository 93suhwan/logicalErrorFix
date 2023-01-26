#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long x;
    cin >> x;
    long long l = int(sqrt(x)), r = int(sqrt(x)) + 1;
    int mid = l * l + (r * r - l * l) / 2 + 1;
    if (x == 1)
      cout << 1 << " " << 1 << '\n';
    else if (x == l * l)
      cout << l << " " << 1 << '\n';
    else if (x == mid)
      cout << l << " " << l << '\n';
    else if (x < mid) {
      cout << x - l * l << " " << l + 1 << '\n';
    } else
      cout << r << " " << r * r - x + 1 << '\n';
  }
  return 0;
}
