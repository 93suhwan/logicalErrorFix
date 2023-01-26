#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void flashSpeed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long N = 2e5 + 5;
long long fact[N];
double Round(double var) {
  float value = (long long)(var * 100 + .5);
  return (float)value / 100;
}
long long ceils(long long x, long long y) { return x / y + ((x % y) != 0); }
long long Gcd(long long a, long long b) {
  if (b > a) {
    return Gcd(b, a);
  }
  if (b == 0)
    return a;
  else
    return Gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / Gcd(a, b) * b; }
bool isPal(string s) {
  for (long long i = 0; i < (long long)s.size() / 2; i++) {
    if (s[i] != s[(long long)s.size() - 1 - i]) return false;
  }
  return true;
}
long long Sumdigits(long long a) {
  long long total = 0;
  while (a) {
    total += a % 10;
    a /= 10;
  }
  return total;
}
bool isPerfectSquare(long long n) {
  for (long long i = 1; i * i <= n; i++) {
    if ((n % i == 0) && (n / i == i)) {
      return true;
    }
  }
  return false;
}
bool isPowerOfTwo(long long n) { return (ceil(log2(n)) == floor(log2(n))); }
void lexosmaintest(string s, string c) {
  string t1 = s;
  sort(t1.begin(), t1.end());
  long long index = -1;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] != t1[i]) {
      index = i;
      break;
    }
  }
  long long j;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == t1[index]) j = i;
  }
  swap(s[index], s[j]);
}
const long long NN = 1e4 + 5;
long long primes[NN];
vector<long long> pr;
void sieve() {
  for (long long i = 2; i < NN; i++) {
    if (primes[i] == 0) {
      pr.push_back(i);
      for (long long j = i * i; j < NN; j += i) {
        primes[j] = 1;
      }
    }
    primes[i] ^= 1;
  }
}
const long long mod2 = 998244353;
long long powerr(long long x, long long y, long long p = mod2) {
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
long long iAmUseless(long long n) {}
const double PI = acos(-1);
long long lefty[N];
long long righty[N];
void chaloTryKrteHai() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  if (a == b == c == m == 1) {
    cout << "NO" << endl;
    return;
  }
  long long sum = a + b + c;
  long long rem = sum - (m + 1);
  if (a > m || b > m || c > m) {
    if (rem > 1) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int32_t main() {
  flashSpeed();
  sieve();
  long long t = 1;
  cin >> t;
  while (t--) {
    chaloTryKrteHai();
  }
  return 0;
}
