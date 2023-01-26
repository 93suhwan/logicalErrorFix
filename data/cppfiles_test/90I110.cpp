#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    if (x > y)
      cout << x + y << '\n';
    else if (x == y)
      cout << x << '\n';
    else {
      long long int k = (x + y) / 2;
      cout << k << '\n';
    }
  }
  return 0;
}
