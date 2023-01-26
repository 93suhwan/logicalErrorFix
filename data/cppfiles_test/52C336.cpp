#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long mod = 1e9 + 7;
long long qmi(long long a, long long k, long long p) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * a % p;
    k >>= 1;
    a = a * a % p;
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  string s;
  while (k) {
    s += (char)(k % 2 + '0');
    k /= 2;
  }
  long long l = s.size();
  long long ans = 0;
  for (long long i = 0; i < l; i++) {
    if (s[i] == '1') ans = (ans + qmi(n, i, mod)) % mod;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
