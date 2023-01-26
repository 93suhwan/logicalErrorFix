#include <bits/stdc++.h>
using namespace std;
const long long special_prime = 982451653l;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &i : a) cin >> i;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &a) {
  for (auto &i : a) cout << i << " ";
  return out;
}
long long power(long long x, long long y, long long p = mod) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p = mod) {
  return power(n, p - 2, p);
}
long long nCrModP(long long n, long long r, long long p = mod) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<long long> fact(n + 1, 1);
  for (long long i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % p;
  return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) %
          p) %
         p;
}
void precompute() {}
void solve(long long T) {
  long long n, e, k;
  cin >> n >> e >> k;
  k -= 2;
  if (k < 0 or e > ((n * (n - 1)) / 2) or e < (n - 1))
    cout << "NO\n";
  else {
    if (k >= 2)
      cout << "YES\n";
    else if (k >= 1 and e == ((n * (n - 1)) / 2))
      cout << "YES\n";
    else if (k == 0 and e == 0 and n == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  precompute();
  cout << setprecision(8) << fixed;
  for (long long i = 1; i <= t; i++) solve(i);
}
