#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long m) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power((x * x) % m, y / 2, m);
  else
    return (x * power((x * x) % m, (y - 1) / 2, m)) % m;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x <= y) {
    cout << y - y % x / 2 << endl;
  } else {
    cout << x + y << endl;
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
