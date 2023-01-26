#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b > d) {
    while (b > d) {
      a *= 10;
      b--;
    }
  } else if (b < d) {
    while (b < d) {
      c *= 10;
      d--;
    }
  }
  if (a > c) {
    cout << ">";
  } else if (a < c) {
    cout << "<";
  } else {
    cout << "=";
  }
}
