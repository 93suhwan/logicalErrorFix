#include <bits/stdc++.h>
using namespace std;
int ary[1001];
int main() {
  long long t, n, ans, r;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 10 == 0 || n % 10 == 9) {
      r = ceil((n * 1.0) / 10);
      ans = r * 25;
    } else if (n % 10 <= 2) {
      r = n / 10;
      if (r == 0) {
        ans = 15;
      } else {
        ans = (r - 1) * 25 + 30;
      }
    } else if (n % 10 <= 4) {
      r = n / 10;
      if (r == 0) {
        ans = 15;
      } else {
        ans = (r - 1) * 25 + 35;
      }
    } else if (n % 10 <= 6) {
      r = n / 10;
      if (r == 0) {
        ans = 15;
      } else {
        ans = (r - 1) * 25 + 40;
      }
    } else if (n % 10 <= 8) {
      r = n / 10;
      if (r == 0) {
        ans = 20;
      } else {
        ans = (r - 1) * 25 + 45;
      }
    }
    cout << ans << endl;
  }
}
