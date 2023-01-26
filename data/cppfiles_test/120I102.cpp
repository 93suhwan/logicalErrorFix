#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, x, cnt = 0, y, k;
    cin >> l >> r;
    y = l;
    x = l;
    int a = r - l;
    while (a--) {
      y++;
      if (x != 0) k = x;
      x &= y;
      if (x == 0) {
        x = k;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
