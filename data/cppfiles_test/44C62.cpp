#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int a, b;
void solve() {
  cin >> a >> b;
  if (a == b && a == 0) {
    cout << 0 << '\n';
    return;
  }
  if ((a + b) % 2 == 1) {
    cout << -1 << '\n';
    return;
  }
  if (a == b)
    cout << 1 << '\n';
  else
    cout << 2 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int __ = 1;
  cin >> __;
  while (__--) solve();
  return 0;
}
