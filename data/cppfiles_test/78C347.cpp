#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, l, r, b, a, t, j;
  cin >> t;
  l = 0;
  while (t--) {
    cin >> a >> b;
    if (a <= (b / 2))
      cout << b - (b / 2) - 1 << '\n';
    else
      cout << (b - a) << '\n';
  }
}
