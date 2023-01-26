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
    ll k;
    cin >> k;
    vector<ll> v(n);
    ll i;
    map<ll, ll> m;
    vector<ll> ans(n, 0LL);
    for (i = 0; i < n; i++) cin >> v[i], m[v[i]]++;
    for (i = 0; i < n; i++) m[v[i]] = min(m[v[i]], k);
    for (i = 0; i < n; i++) {
      if (m[v[i]] > 0) {
        ans[i] = m[v[i]]--;
      }
    }
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
