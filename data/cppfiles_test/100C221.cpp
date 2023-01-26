#include <bits/stdc++.h>
using namespace std;
const long long C1 = 1e9 + 7;
const long long C2 = 998244353;
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
long long binpow(long long a, long long b, long long m = C1) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
vector<long long> fac(200001);
vector<long long> invfac(200001);
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long cnt{};
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long m = *max_element(v.begin(), v.end());
  map<long long, long long> freq;
  for (long long i = 0; i < n; i++) {
    if (m == v[i]) cnt++;
    freq[v[i]]++;
  }
  if (cnt == 1) {
    if (freq[m - 1] != 0) {
      long long x = freq[m - 1];
      long long ans = fac[n];
      ans -= ((fac[n] * binpow(x + 1, C2 - 2, C2)) % C2);
      ans += C2;
      ans %= C2;
      cout << ans << '\n';
    } else {
      cout << 0 << '\n';
    }
  } else {
    long long ans = fac[n];
    cout << ans << '\n';
  }
}
signed main() {
  long long t = 1;
  cin >> t;
  fac[0] = 1;
  fac[1] = 1;
  for (long long i = 2; i <= 2e5; i++) {
    fac[i] = (fac[i - 1] * i) % C2;
  }
  invfac[200000] = binpow(fac[200000], C2 - 2, C2);
  for (long long i = 200000 - 1; i >= 1; i--) {
    invfac[i] = (invfac[i + 1] * (i + 1)) % C2;
  }
  while (t--) {
    solve();
  }
}
