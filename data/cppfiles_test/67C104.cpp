#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long M = 1e9 + 10;
int x, xx, a, b, c;
bool check(int i) {
  if (i < 1 || i > xx) return 0;
  return 1;
}
void solve() {
  cin >> a >> b >> c;
  x = abs(a - b);
  xx = 2 * x;
  if (c > xx || a > xx || b > xx)
    cout << -1 << '\n';
  else {
    int i = c + x;
    int j = c - x;
    if (i == a || i == b || j == a || j == b)
      cout << -1 << '\n';
    else {
      if (check(i) && check(j))
        cout << -1 << '\n';
      else if (check(i))
        cout << i << '\n';
      else if (check(j))
        cout << j << '\n';
      else
        cout << -1 << '\n';
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
