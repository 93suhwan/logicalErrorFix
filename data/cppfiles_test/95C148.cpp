#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int sum, n;
  cin >> sum >> n;
  long long int val = 1000000000;
  while (val > 0) {
    if (n <= 1) break;
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
