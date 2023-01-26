#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, n;
  cin >> a >> b >> c;
  if (a > b) {
    swap(a, b);
  }
  int i = (b - a) - 1;
  int j = (a - 1);
  if (i < 0 || i < j) {
    cout << -1 << endl;
    return;
  }
  if ((b + i - j) % 2 == 0 && b + i - j >= c) {
    if ((b + (c - a)) > (b + i - j)) {
      cout << (b + c - a) - (b + i - j) << endl;
    } else {
      cout << b + c - a << endl;
    }
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, tc;
  t = 1, tc = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
