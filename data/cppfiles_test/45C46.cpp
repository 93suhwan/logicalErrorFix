#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e6 + 5;
const long long int modn = 1e9 + 7;
const double pi = acos(-1);
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 1; i < n; i++) {
    if (a[i] == 0 && a[i - 1] == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  long long int ans = 1, l = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == 1) {
      l++;
    } else {
      if (l == 0) continue;
      ans += 5 * (l - 1) + 1;
      l = 0;
    }
  }
  if (l > 0) {
    ans += 5 * (l - 1) + 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int test_case = 1;
  cin >> test_case;
  for (long long int i = 1; i <= test_case; i++) {
    solve();
  }
  return 0;
}
