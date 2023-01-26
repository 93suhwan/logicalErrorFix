#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = power(a, b / 2);
  ans = (ans * ans) % 1000000007;
  if (b % 2) {
    ans *= a;
  }
  return ans % 1000000007;
}
void solve() {
  long long k;
  cin >> k;
  long long node = (1LL << k) - 2;
  long long ans = power(4, node);
  ans = (ans * 6) % 1000000007;
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
