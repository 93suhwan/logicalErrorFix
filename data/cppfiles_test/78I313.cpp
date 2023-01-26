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
    if (l == r) {
      cout << "0\n";
      continue;
    }
    if (m > l) {
      cout << (r - 1) / 2 << "\n";
    } else {
      int ans = r % l;
      if (ans == 0) {
        ans = r % (l + 1);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
