#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long bp(long long a, long long b, long long mod) {
  if (b == 0LL) return 1LL;
  if (b % 2LL == 0LL) {
    long long tmp = bp(a, b / 2LL, mod);
    return tmp * tmp % mod;
  }
  return a * bp(a, b - 1LL, mod) % mod;
}
int solve() {
  long long n;
  cin >> n;
  if (n == 1LL) return cout << 1 << '\n', 0;
  long long ans = 1;
  for (long long i = 2; i <= 2LL * n; ++i) {
    ans = (ans * i) % (long long)(1e9 + 7LL);
  }
  cout << ans * bp(2, 1e9 + 5, 1e9 + 7) % (long long)(1e9 + 7LL) << '\n';
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
