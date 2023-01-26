#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int r = abs(a - b);
    cout << ((r * 2 >= c && r > 1) ? ((c % r) + r) : -1) << "\n";
  }
  return 0;
}
