#include <bits/stdc++.h>
using namespace std;
const int N = 1500;
const long long int MOD = 998244353;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrMODp(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void divisors(int n) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cout << " " << i;
      else
        cout << " " << i << " " << n / i;
    }
  }
}
void primeFactors(int n) {
  while (n % 2 == 0) {
    cout << 2 << " ";
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      cout << i << " ";
      n = n / i;
    }
  }
  if (n > 2) cout << n << " ";
}
void solve() {
  int i, x = 0, y = 0;
  string str;
  cin >> str;
  for (i = 0; i < str.size(); i++) str[i] == 'B' ? x++ : y++;
  y == x ? cout << "YES\n" : cout << "NO\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
