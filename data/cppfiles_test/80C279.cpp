#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool isPrime(ll n) {
  if (n <= 1) return false;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
void sieve(ll n) {
  vector<bool> prime(n + 1, true);
  for (ll p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (ll i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
ll modular(ll x, unsigned long long int y, ll p) {
  ll res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll i;
    ll l1 = -1, r1, l2, r2;
    for (i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        l1 = 0;
        r1 = i;
        l2 = 0;
        r2 = i - 1;
        break;
      }
    }
    if (l1 == -1) {
      for (i = 0; i <= n / 2; i++) {
        if (s[i] == '0') {
          l1 = i;
          r1 = n - 1;
          l2 = i + 1;
          r2 = n - 1;
          break;
        }
      }
    }
    if (count(s.begin(), s.end(), '1') == n) {
      l1 = 0;
      r1 = n / 2 - 1;
      l2 = 1;
      r2 = n / 2;
    }
    cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << "\n";
  }
  return 0;
}
