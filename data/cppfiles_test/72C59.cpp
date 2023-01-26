#include <bits/stdc++.h>
using namespace std;
int query(int a, int b) {
  cout << "? " << a << " " << b << "\n";
  cout.flush();
  int res;
  cin >> res;
  return res;
}
bool answer(int x, int y, int p, int q) {
  cout << "! " << x << " " << y << " " << p << " " << q << "\n";
  cout.flush();
  return true;
}
void solve() {
  int a, b, c, d, n = 1e9, yq, xp, x, y, p, q;
  a = query(1, 1);
  b = query(1, n);
  d = query(n, n);
  yq = a - b + 1 + n;
  xp = b - d + 1 + n;
  x = query(1, yq / 2) + 1;
  y = a - x + 2;
  q = x - 1 + n - b;
  p = 2 * n - d - q;
  answer(x, y, p, q);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  solve();
  return 0;
}
