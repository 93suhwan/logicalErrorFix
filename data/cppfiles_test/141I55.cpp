#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, s;
  cin >> a >> s;
  string b = "";
  while (s != 0 and a != s) {
    if (a > s) {
      cout << -1 << "\n";
      return;
    }
    if (s % 10 >= a % 10) {
      b = (char)(s % 10 - a % 10 + 48) + b;
      a = a / 10;
      s = s / 10;
    } else {
      if (s % 100 - a % 10 > 9 or s % 100 == 0) {
        cout << -1 << "\n";
        return;
      }
      b = (char)(s % 100 - a % 10 + 48) + b;
      a = a / 10;
      s = s / 100;
    }
  }
  cout << b << "\n";
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
