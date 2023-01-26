#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h;
  cin >> w >> h;
  int k, max1 = 0, max2 = 0;
  for (int j = 1; j <= 4; j++) {
    cin >> k;
    int l, r;
    for (int i = 1; i <= k; i++) {
      int x;
      cin >> x;
      if (i == 1) l = x;
      if (i == k) r = x;
    }
    if (j == 1 || j == 2) max1 = max(r - l, max1);
    if (j == 3 || j == 4) max2 = max(max2, r - l);
  }
  if (max1 * h > max2 * w)
    cout << max1 * h << endl;
  else
    cout << max2 * w << endl;
}
int main() {
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
