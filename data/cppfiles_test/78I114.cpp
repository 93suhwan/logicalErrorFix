#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int test = 1;
  cin >> test;
  while (test--) {
    int l, r;
    cin >> l >> r;
    int m = r / 2;
    if (m > l) {
      cout << r % (m + 1) << "\n";
    } else {
      int ans = 0;
      cout << r % l << "\n";
    }
  }
  return 0;
}
