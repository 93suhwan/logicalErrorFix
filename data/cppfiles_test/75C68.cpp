#include <bits/stdc++.h>
using namespace std;
const long long mx = 200001;
const long long mod = 1e9 + 7;
const long double PI = 3.141592653589793238460;
void __print(long long x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rng(0, 1);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return ((long long)ceil(log2(n)) == (long long)floor(log2(n)));
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long divide(long long a, long long b) {
  return (a % mod) * powm(b, mod - 2) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long add(long long a, long long b) { return (a % mod + b % mod) % mod; }
long long Totfun(long long n) {
  long long z = n;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      n /= 2;
    }
    z /= 2;
  }
  for (long long i = 3; i * i <= n; i += 2) {
    if (isPrime(i) && n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      z -= z / i;
    }
  }
  if (n > 1) {
    z -= z / n;
  }
  return z;
}
long long fact[mx];
long long nCr(long long n, long long r) {
  if (r > n || r < 0) return 0;
  long long z = fact[n];
  z = mul(z, powm(fact[n - r], mod - 2));
  z = mul(z, powm(fact[r], mod - 2));
  return z;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long x = 0;
  while (x < n - 1 && a[x + 1] > a[x]) x++;
  long long y = n - 1;
  while (y > 0 && a[y - 1] > a[y]) y--;
  x++;
  y = n - y;
  if (x % 2 == 0 && y % 2 == 0)
    cout << "Bob\n";
  else
    cout << "Alice\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  long long t = 1;
  while (t--) solve();
  return 0;
}
