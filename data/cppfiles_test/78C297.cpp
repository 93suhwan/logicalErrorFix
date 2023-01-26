#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, l;
    cin >> l >> r;
    if (r < l * 2) {
      cout << r - l << endl;
    } else {
      cout << (r - 1) / 2 << endl;
    }
  }
}
