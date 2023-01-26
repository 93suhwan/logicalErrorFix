#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h;
  cin >> w >> h;
  int kxd, kxu;
  cin >> kxd;
  int a1[kxd];
  for (int i = 0; i < kxd; i++) {
    cin >> a1[i];
  }
  cin >> kxu;
  int a2[kxu];
  for (int i = 0; i < kxu; i++) {
    cin >> a2[i];
  }
  int kyl, kyr;
  cin >> kyl;
  int b1[kyl];
  for (int i = 0; i < kyl; i++) {
    cin >> b1[i];
  }
  cin >> kyr;
  int b2[kyr];
  for (int i = 0; i < kyr; i++) {
    cin >> b2[i];
  }
  int diff1 = *max_element(a1, a1 + kxd) - *min_element(a1, a1 + kxd);
  int diff2 = *max_element(a2, a2 + kxu) - *min_element(a2, a2 + kxu);
  int diff3 = *max_element(b1, b1 + kyl) - *min_element(b1, b1 + kyl);
  int diff4 = *max_element(b2, b2 + kyr) - *min_element(b2, b2 + kyr);
  int ans1 = diff1 * h;
  int ans2 = diff2 * h;
  int ans3 = diff3 * w;
  int ans4 = diff4 * w;
  cout << max(max(ans1, ans2), max(ans3, ans4)) << endl;
}
int32_t main() {
  int n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
