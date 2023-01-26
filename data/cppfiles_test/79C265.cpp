#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 0;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long modpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool checksq(long long num) {
  return floor((double)sqrt(num)) == ceil((double)sqrt(num));
}
bool ispoweroftwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
void ghost() {
  cout << "Apun Red Coder banega"
       << "\n";
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << "\n";
      cout << s[i] << "\n";
      return;
    }
  }
  for (long long i = 0; i < n; i++) {
    string str;
    str += s[i];
    for (long long j = i + 1; j < n; j++) {
      str += s[j];
      if (!isprime(stoi(str))) {
        cout << 2 << "\n";
        cout << str << "\n";
        return;
      }
      str.pop_back();
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
