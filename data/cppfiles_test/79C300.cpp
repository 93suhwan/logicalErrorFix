#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long b[100] = {};
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> v(n);
  long long x = -1;
  long long y = -1;
  for (long long i = 0; i < n; i++) {
    v[i] = (long long)(s[i] - '0');
    if (v[i] == 1 || v[i] == 4 || v[i] == 6 || v[i] == 8 || v[i] == 9) {
      x = 1;
      y = v[i];
    }
  }
  if (x != -1) {
    cout << x << endl;
    cout << y << endl;
    return;
  }
  long long f = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long a = v[j] + 10 * v[i];
      if (!b[a]) {
        x = 2;
        y = a;
        f = 1;
        break;
      }
    }
    if (f == 1) break;
  }
  cout << x << endl;
  cout << y << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 100; i++) {
    if (isPrime(i)) b[i] = 1;
  }
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
