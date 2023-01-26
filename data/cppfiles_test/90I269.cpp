#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10, mod = 1e9 + 7;
long long x, y;
void solve() {
  cin >> x >> y;
  cout << y - (y % x) / 2 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
