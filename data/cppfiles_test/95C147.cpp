#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int sum, n, val = 1000000000;
  cin >> sum >> n;
  while (val > 0 and n > 1) {
    if ((sum - val) >= (n - 1)) {
      cout << val << ' ';
      sum -= val;
      n--;
    } else
      val /= 10;
  }
  cout << sum << '\n';
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tt;
  cin >> tt;
  while (tt--) solve();
  cerr << " Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s \n";
  return 0;
}
