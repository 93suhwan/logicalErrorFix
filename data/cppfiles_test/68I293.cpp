#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
const long long infll = 1e18 + 1;
void solve() {
  int k;
  cin >> k;
  int d = sqrt(k);
  if (d * d == k) {
    cout << d << ' ' << 1 << '\n';
    return;
  }
  d++;
  int x = 1, y = d;
  for (int i = d * d; i > d * d - d; i--) {
    if (i == k) {
      cout << y << ' ' << x << '\n';
      return;
    }
    x++;
  }
  x--;
  for (int i = d * d - d; i > (d - 1) * (d - 1); i--) {
    if (i == k) {
      cout << y << ' ' << x << '\n';
      return;
    }
    y--;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
