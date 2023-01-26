#include <bits/stdc++.h>
using namespace std;
void solve() {
  long l, r;
  cin >> l >> r;
  long p = max(l, r / 2 + 1);
  long ans = r % p;
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t-- > 0) solve();
}
