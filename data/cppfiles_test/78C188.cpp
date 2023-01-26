#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l <= r / 2)
      cout << (r + 1) / 2 - 1 << endl;
    else
      cout << r - l << endl;
  }
  return 0;
}
