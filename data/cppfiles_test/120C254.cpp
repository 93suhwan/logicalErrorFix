#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
long long int get(long long int n, long long int k) {
  long long int ans = (n >> (k + 1)) << k;
  if ((n >> k) & 1) ans += n & ((1ll << k) - 1);
  return ans;
}
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int ans = int_max;
  for (long long int i = 0; i <= 30; i++) {
    ans = min(ans, r - l + 1 - (get(r + 1, i) - get(l, i)));
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
