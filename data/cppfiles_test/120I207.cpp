#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
void solve() {
  int a, b;
  cin >> a >> b;
  int x = 1, size = b - a + 1;
  while (x * 2 < b) {
    x *= 2;
  }
  int ans = (x * 2 == b ? size - b + x : size - b + x - 1);
  cout << min(ans, size - x + a) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
