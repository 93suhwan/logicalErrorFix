#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
long long n, ans;
long long a[MAX_N];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    cin >> a[i], ans = max(ans, a[i] * a[i - 1]);
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
