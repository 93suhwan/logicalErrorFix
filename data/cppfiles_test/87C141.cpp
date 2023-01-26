#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 5e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1);
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long re() {
  long long x;
  scanf("%lld", &x);
  return x;
}
long long qk(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
long long a[1000];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, max(0ll, a[i] - i));
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
