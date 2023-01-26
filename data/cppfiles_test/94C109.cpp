#include <bits/stdc++.h>
using namespace std;
long long maxn = 2000001;
long long mod = 1000000007;
vector<long long> sieveVector(maxn + 1, 1);
vector<long long> factVector(maxn + 1, 1);
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      res = res * a, b--;
    else
      a = a * a, b /= 2;
  }
  return res;
}
long long powerMod(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b % 2)
      res = (res % m * a % m) % m, b--;
    else
      a = (a % m * a % m) % m, b /= 2;
  }
  return res;
}
long long modIn(long long n, long long m) { return powerMod(n, m - 2, m); }
void factorial() {
  for (long long i = 1; i <= maxn; i++)
    factVector[i] = (i % mod * factVector[i - 1] % mod);
}
void sieve() {
  for (long long i = 2; i * i <= maxn; i++) {
    if (sieveVector[i]) {
      for (long long j = i * i; j <= maxn; j += i) {
        sieveVector[j] = 0;
      }
    }
  }
}
long long ncr(long long n, long long r) {
  if (r > n) return 0;
  return (factVector[n] % mod *
          modIn((factVector[n - r] % mod * factVector[r] % mod) % mod, mod)) %
         mod;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long I = 0; I < n; I++) cin >> v[I];
  ;
  long long ans = 0;
  k++;
  for (long long i = 0; i < n - 1; i++) {
    if (!k) break;
    long long d = power(10, v[i + 1]) - 1;
    long long maxe = d / power(10, v[i]);
    ans += min(k, maxe) * power(10, v[i]);
    k -= min(k, maxe);
  }
  ans += (k * power(10, v.back()));
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc;
  cin >> tc;
  while (tc--) solve();
}
