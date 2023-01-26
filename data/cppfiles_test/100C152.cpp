#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  multiset<long long> order;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    order.insert(a);
  }
  long long add = 0, ans = -1e18;
  while (order.size() > 1) {
    long long cur = *order.begin() + add;
    ans = max(ans, cur);
    add -= cur;
    order.erase(order.begin());
  }
  ans = max(ans, *order.begin() + add);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
