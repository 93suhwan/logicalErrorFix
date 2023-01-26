#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 1e5 + 10;
const long double eps = 1e-6;
void solve() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << "\n";
    return;
  }
  if (x > y) {
    cout << (x + y) << "\n";
    return;
  }
  int t = (x + y) / 2, k = y % t;
  if (k == t % x) {
    cout << t << "\n";
    return;
  }
  t += k - x;
  t += (x - (t % x)) / 2;
  cout << t << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
