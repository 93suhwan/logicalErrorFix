#include <bits/stdc++.h>
using namespace std;
int xorr[300005];
void solve() {
  int a, b;
  cin >> a >> b;
  if (xorr[a - 1] == b)
    cout << a << "\n";
  else
    cout << ((xorr[a - 1] ^ b) == a ? a + 2 : a + 1) << "\n";
}
void _pre() {
  xorr[0] = 0;
  for (int i = 1; i <= 300000; i++) xorr[i] = i ^ xorr[i - 1];
}
int main() {
  _pre();
  int _ = 1;
  cin >> _;
  for (int t = 1; t <= _; t++) {
    solve();
  }
  return 0;
}
