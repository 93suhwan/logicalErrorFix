#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long binaryexp(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    mp[arr[i]]++;
  }
  long long fact[n + 10];
  fact[0] = 1;
  for (long long i = 1; i < n + 10; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  if (mp.size() == 1) {
    cout << fact[n] << endl;
    return;
  }
  auto it = mp.rbegin();
  long long l = (*it).second;
  long long lval = (*it).first;
  it++;
  long long sval = (*it).first;
  long long s = (*it).second;
  if (lval != sval + 1) {
    cout << 0 << endl;
    return;
  }
  if (l > 1) {
    cout << fact[n] << endl;
    return;
  }
  long long temp1 = fact[n];
  long long temp2 = fact[l + s];
  long long temp3 = binaryexp(temp2, mod - 2, mod);
  long long temp4 = temp1 * temp3 % mod;
  long long temp5 = fact[l];
  long long temp6 = temp4 * temp5 % mod;
  long long temp7 = temp6 * fact[s] % mod;
  long long res = (((fact[n] - temp7) % mod) + mod) % mod;
  cout << res << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
