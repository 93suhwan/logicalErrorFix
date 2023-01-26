#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void solve() {
  ll a, b, c, x, y;
  x = y = 0;
  cin >> a >> b >> c;
  x = c / 2 * 3;
  y = (c / 2 + c % 2) * 3;
  x += (b / 2 + b % 2) * 2;
  y += b / 2 * 2;
  if (abs(x - y) >= a)
    cout << abs(x - y) - a;
  else
    cout << (a - abs(x - y)) % 2;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
