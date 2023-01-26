#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, mod = 998244353;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y)
      cout << (x + y) << endl;
    else
      cout << ((y - y % x + y) >> 1) << endl;
  }
  return 0;
}
