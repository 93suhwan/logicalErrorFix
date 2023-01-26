#include <bits/stdc++.h>
using namespace std;
long long int l, r;
long long int fun(long long int x) {
  long long int ans = 0;
  if (x < l) {
    return 0;
  }
  if (2 * x - 1 <= r) {
    return x - 1;
  }
  return r - x;
}
void solve() {
  cin >> l >> r;
  long long int ans = 0;
  long long int x = r / 2;
  x++;
  ans = max(ans, fun(x));
  x--;
  ans = max(ans, fun(x));
  x = l;
  ans = max(ans, fun(x));
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
