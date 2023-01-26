#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int m = r / 2;
    if (m < l) {
      int re = r % l;
      cout << re << endl;
    } else {
      ++m;
      int re = r % m;
      cout << re << endl;
    }
  }
  return 0;
}
