#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long kxd, kxu;
  cin >> kxd;
  long long a1[kxd];
  for (long long i = 0; i < kxd; i++) {
    cin >> a1[i];
  }
  cin >> kxu;
  long long a2[kxu];
  for (long long i = 0; i < kxu; i++) {
    cin >> a2[i];
  }
  long long kyl, kyr;
  cin >> kyl;
  long long b1[kyl];
  for (long long i = 0; i < kyl; i++) {
    cin >> b1[i];
  }
  cin >> kyr;
  long long b2[kyr];
  for (long long i = 0; i < kyr; i++) {
    cin >> b2[i];
  }
  long long diff1 = *max_element(a1, a1 + kxd) - *min_element(a1, a1 + kxd);
  long long diff2 = *max_element(a2, a2 + kxu) - *min_element(a2, a2 + kxu);
  long long diff3 = *max_element(b1, b1 + kyl) - *min_element(b1, b1 + kyl);
  long long diff4 = *max_element(b2, b2 + kyr) - *min_element(b2, b2 + kyr);
  long long ans1 = diff1 * h;
  long long ans2 = diff2 * h;
  long long ans3 = diff3 * w;
  long long ans4 = diff4 * w;
  cout << max(max(ans1, ans2), max(ans3, ans4)) << endl;
}
int32_t main() {
  long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
