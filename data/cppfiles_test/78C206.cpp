#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int l, r;
    cin >> l >> r;
    if (l == r)
      cout << 0 << endl;
    else if ((r) / 2 + 1 >= l)
      cout << r % ((r) / 2 + 1) << endl;
    else
      cout << r % l << endl;
  }
}
