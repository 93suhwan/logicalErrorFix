#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int ans = 0;
  long long int x = r / 2;
  if (x + x - 1 <= r && x >= l) {
    ans = max(ans, x - 1);
  }
  x++;
  if (x + x - 1 <= r && x >= l) {
    ans = max(ans, x - 1);
  }
  x--;
  if (x + x - 1 <= r && x >= l) {
    ans = max(ans, x - 1);
  }
  x = l;
  if (x + x - 1 <= r && x >= l) {
    ans = max(ans, x - 1);
  }
  if (!ans) {
    ans = max(ans, r - l);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, q;
  q = 1;
  cin >> q;
  for (t = 1; t <= q; t++) {
    solve();
  }
}
