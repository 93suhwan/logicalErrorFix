#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int tot = abs(a - b) * 2;
  if (a > tot || b > tot || c > tot) {
    cout << -1 << endl;
    return;
  }
  if (c - tot / 2 > 0)
    cout << c - tot / 2 << endl;
  else if (c + tot / 2 <= tot)
    cout << c + tot / 2 << endl;
  else
    cout << -1 << endl;
}
int main() {
  int tests;
  cin >> tests;
  while (tests--) solve();
  return 0;
}
