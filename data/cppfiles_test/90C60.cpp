#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
void solve() {
  long long int x, y, n;
  cin >> x >> y;
  if (y % x == 0)
    n = x;
  else {
    if (x > y)
      n = x + y;
    else {
      n = y - (y % x) / 2;
    }
  }
  cout << n << "\n";
  return;
}
