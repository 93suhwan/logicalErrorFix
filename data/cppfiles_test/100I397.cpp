#include <bits/stdc++.h>
using namespace std;
const double delta = 0.0000000001;
const double pi = 3.1415926535;
long long MOD = 998244353;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void __print() { cerr << "]\n"; }
template <typename T, typename... V>
void __print(T t, V... v) {
  _print(t);
  if (sizeof...(v)) cerr << ", ";
  __print(v...);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long x = gcd(a, b);
  long long ans = (a * b) / x;
  return ans;
}
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extendedGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
long long modInverse(long long n, long long t) { return expo(n, t - 2, t); }
void factors(long long n) {
  vector<long long> factor;
  for (long long i = 1; i * i <= n; i++)
    if (n % i == 0) {
      if (n / i == i)
        factor.push_back(i);
      else {
        factor.push_back(i);
        factor.push_back(n / i);
      }
    }
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
unsigned long long nCrModPFermat(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<unsigned long long> fac(n + 1);
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
  return (fac[n] * modInverse(fac[r], MOD) % MOD * modInverse(fac[n - r], MOD) %
          MOD) %
         MOD;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> m;
  long long l = -1;
  long long tot = 1;
  for (long long i = (0); i <= (n - 1); i++) {
    cin >> a[i];
    m[a[i]]++;
    l = max(l, a[i]);
    tot = (tot * (i + 1)) % MOD;
  }
  if (m[l] > 1) {
    cout << tot << "\n";
    return;
  }
  tot = (tot * m[l - 1]) % MOD;
  tot = tot / (m[l - 1] + 1);
  cout << tot << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
