#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int solve() {
  long long n;
  cin >> n;
  long long ans = 1;
  for (long long i = 2; i <= 2LL * n; ++i) {
    ans = (ans * i) % (long long)(1e9 + 7LL);
  }
  cout << ans << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
