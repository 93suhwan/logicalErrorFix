#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long int binPow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * a) % MOD;
    a = (1LL * a * a) % MOD;
    n >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long int ncr(long long int n, long long int k,
                  const vector<long long int>& fact,
                  const vector<long long int>& inv) {
  if (k > n) return 0;
  long long int m = (1LL * fact[n] * inv[k]) % MOD;
  m = (1LL * m * inv[n - k]) % MOD;
  return m;
}
void solve() {
  long long int n, s = 0;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (long long int i = 0; i < n - 1; i++) {
    s += v[i];
  }
  double avg = (double)s / (n - 1);
  avg += v[n - 1];
  cout << fixed << setprecision(9) << avg << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
