#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1000000007;
long long mod2 = 998244353;
long long inf = mod1 * mod1;
long long powe(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = (res * a) % mod1;
    b /= 2;
    a = (a * a) % mod1;
  }
  return res;
}
void solve() {
  long long n, i, k, ans = 0, x = 1;
  cin >> n >> k;
  while (k) {
    if (k % 2) {
      ans = (ans + x) % mod1;
    }
    x = (x * n) % mod1;
    k /= 2;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
