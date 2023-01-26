#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const unsigned long long int mod = 1e9 + 7;
const long long int inf = 1000000000000000000;
const long double pi = 3.14159265358979323846264338;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int modpow(long long int x, unsigned long long int y,
                     unsigned long long int m) {
  if (y == 0) return 1;
  long long int p = modpow(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long int pow(long long int a, long long int b) {
  if (!b) return 1;
  long long int temp = pow(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
long long int ncr(long long int n, long long int r, long long int p) {
  long long int num = 1, den = 1;
  for (long long int i = 0; i < r; i++) {
    num = (num * (n - i)) % p;
    den = (den * (i + 1)) % p;
  }
  return (num * modpow(den, p - 2, p)) % p;
}
void solve() {
  long long int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    a[i] = (s[i] == '+') ? 1 : -1;
  }
  vector<long long int> pref0(n + 1);
  long long int sum1 = 0;
  for (long long int i = 0; i <= n; i++) {
    pref0[i] = sum1;
    if (i < n) {
      sum1 += (i % 2 == 0) ? a[i] * (1) : a[i] * (-1);
    }
  }
  long long int x, y;
  for (long long int i = 0; i < q; i++) {
    cin >> x >> y;
    if (pref0[y] - pref0[x - 1] == 0) {
      cout << 0 << endl;
    } else if (abs((pref0[y] - pref0[x - 1]) % 2) == 1) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
