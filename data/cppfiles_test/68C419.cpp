#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, k, a[100][2], r, x;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> k;
    r = sqrt(k);
    if (k == r * r) {
      a[i][0] = r;
      a[i][1] = 1;
      continue;
    }
    x = k - r * r;
    if (x <= (r + 1)) {
      a[i][0] = x;
      a[i][1] = r + 1;
    } else {
      a[i][0] = r + 1;
      a[i][1] = 2 * (r + 1) - x;
    }
  }
  for (i = 0; i < t; i++) cout << a[i][0] << " " << a[i][1] << endl;
  return 0;
}
