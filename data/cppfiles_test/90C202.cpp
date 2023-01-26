#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << "\n";
  } else if (x < y) {
    long long m = (y / x) * x;
    cout << (m + y) / 2LL << "\n";
  } else {
    cout << x + y << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
