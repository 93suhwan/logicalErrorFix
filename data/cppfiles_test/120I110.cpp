#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
const int N = 200010;
const int inf = (int)(1e9);
void solve() {
  long long l, r;
  cin >> l >> r;
  long long i, fact = 1;
  for (i = 0; i < 30; i++) {
    if (fact > r) {
      break;
    }
    fact = fact * 2;
  }
  long long pow = i;
  pow--;
  fact = fact / 2;
  long long ans = r - fact + 1;
  ans = r - l + 1 - ans;
  if (fact / 2 >= l) {
    ans = min(ans, r - l + 1 - fact / 2);
  }
  if ((r - l + 1) % 2) {
    if (r % 2) {
      ans = min(ans, (r - l + 1) / 2);
    } else {
      ans = min(ans, (r - l + 1) / 2 + 1);
    }
  } else {
    ans = min(ans, (r - l + 1) / 2 + 1);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
