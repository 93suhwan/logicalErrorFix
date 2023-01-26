#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  cin >> x >> y;
  long long ans = x + (y % x);
  cout << ans << endl;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
