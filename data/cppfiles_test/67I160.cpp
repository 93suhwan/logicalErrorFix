#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5 + 5;
void io_file() {}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long diff = abs(a - b);
  long long x = abs(a - b);
  long long x2 = -1;
  if (c - abs(a - b)) {
    x2 = c - abs(a - b);
  }
  x = x + c;
  long long one = 1 + diff;
  if (diff > 1 && (x < one + diff)) {
    cout << x << endl;
    return;
  } else if (c >= one && diff > 1 && c <= one + diff && one != a && one != b) {
    if (x2) {
      cout << x2 << endl;
    }
    return;
  } else {
    cout << -1 << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  io_file();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
