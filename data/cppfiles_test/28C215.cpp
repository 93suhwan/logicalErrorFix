#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void output(int a, int b, int c) {
  if ((a + 3 * c) % 2 == 0) {
    cout << 0 << endl;
  } else
    cout << 1 << endl;
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a >= 2 && b >= 1) {
    output(a, b, c);
    return;
  }
  if (a == 1 && b >= 3 && c >= 1) {
    output(a, b, c);
    return;
  }
  if (a == 0 && b >= 4 && c >= 2) {
    output(a, b, c);
    return;
  }
  if (b == 0 && a >= 3 && c >= 1) {
    output(a, b, c);
    return;
  }
  int minnum = 10;
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      for (int k = 0; k <= c; k++) {
        int l = i + 2 * j + 3 * k, r = (a - i) + 2 * (b - j) + 3 * (c - k);
        if (r - l < 0) break;
        if (minnum > r - l) minnum = r - l;
        if (minnum == 0) break;
      }
  cout << minnum << endl;
  return;
}
int main() {
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
