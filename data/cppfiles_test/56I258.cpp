#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const long long N = 1e5 + 100;
long long Main() {
  long long long long x = 1, y = 1;
  long long long long p1 = 1;
  while (true) {
    if (x > 8 || y > 8) cout << 1 / 0;
    cout << x << " " << y << endl;
    if (x == 1) p1 = 1;
    string s;
    cin >> s;
    if (s == "Done") return 0;
    if ((s == "Right" || s == "Down-Right" || s == "Up-Right") &&
        (x != 1 || y != 1)) {
      y++;
      p1 = 0;
      continue;
    }
    if ((s == "Left" || s == "Down-Left" || s == "Up-Left") && x != 1) {
      x = 1;
      p1 = 1;
      continue;
    }
    if (p1 == 0) {
      x = 1;
      p1 = 1;
      continue;
    }
    if (x == 7) {
      y++;
      p1 = 0;
      continue;
    }
    x++;
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long long long t;
  cin >> t;
  while (t--) {
    Main();
  }
}
