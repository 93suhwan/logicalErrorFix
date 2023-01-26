#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <typename T, typename... V>
void _print(T t, V... v) {
  _print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void ps(vector<int> arr) {
  for (int i = 0; i < (int)(arr.size()); ++i) cout << arr[i] << ' ';
}
void inp(vector<long long> &arr) {
  int n = arr.size();
  for (int i = 0; i < (int)(n); ++i) cin >> arr[i];
}
void out(vector<long long> &arr) {
  int n = arr.size();
  for (int i = 0; i < (int)(n); ++i) cout << arr[i] << ' ';
}
void inp(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < (int)(n); ++i) cin >> arr[i];
}
void out(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < (int)(n); ++i) cout << arr[i] << ' ';
}
long long binpow(long long a, long long b, long long mod = 1e9 + 7) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
vector<long long> factorial(int n, long long mod = 1e9 + 7) {
  vector<long long> fact(n + 2);
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  return fact;
}
vector<bool> sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  vector<int> allPrime;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      allPrime.push_back(i);
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}
void yes() { cout << "YES"; }
void no() { cout << "NO"; }
long long inverse(long long a, long long m = 1e9 + 7) {
  a %= m;
  return binpow(a, m - 2, m);
}
long long mul(long long a, long long b, long long m = 1e9 + 7) {
  a %= m;
  b %= m;
  return (a * b) % m;
}
long long add(long long a, long long b, long long m = 1e9 + 7) {
  a %= m;
  b %= m;
  return (a + b) % m;
}
const long long mod = 1e9 + 7;
const long long inf = INT_MAX;
const int N = 200003;
const char nl = '\n';
vector<long long> fact = factorial(N);
void solve() {
  int n;
  cin >> n;
  long long ans = 6;
  for (int i = 2; i <= n; i++) {
    long long node = (1ll << (i - 1));
    ans = mul(ans, binpow(4, node));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int kickstart = 1;
  long long tt;
  tt = 1;
  while (tt--) {
    solve();
    cout << nl;
  }
  return 0;
}
