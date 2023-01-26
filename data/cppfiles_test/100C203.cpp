#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long MOD = 998244353;
long long fact[N], invfact[N];
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long modinv(long long k) { return pow(k, MOD - 2, MOD); }
void precompute() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  invfact[N - 1] = modinv(fact[N - 1]);
  for (long long i = N - 2; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1);
    invfact[i] %= MOD;
  }
}
long long n;
long long a[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  precompute();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    map<long long, long long> m;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    long long mx = a[n];
    long long mx2 = a[n - 1];
    if (mx == mx2) {
      long long ans = fact[n];
      cout << ans << "\n";
    } else if (mx > mx2 + 1)
      cout << 0 << "\n";
    else {
      long long totalWays = fact[n];
      long long invalidWays = (fact[n] * modinv(m[mx2] + 1)) % MOD;
      long long ans = (totalWays - invalidWays + MOD) % MOD;
      cout << ans << "\n";
    }
  }
  return 0;
}
