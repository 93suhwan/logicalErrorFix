#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 4;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
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
vector<long long> first(N, 1), INV(N, 1), minp(N, 0);
vector<bool> prime(N, 0);
long long gd(long long a, long long b) {
  if (b == 0) return a;
  return gd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gd(a, b); }
long long ex(long long x, long long n) {
  long long res = 1;
  x = x % mod;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n = n >> 1;
  }
  return res % mod;
}
long long fermat(long long n) { return ex(n, mod - 2); }
void fact() {
  for (int i = 2; i < N; i++) {
    first[i] = (first[i - 1] * i) % mod;
    INV[i] = fermat(first[i]);
  }
}
long long ncr(long long n, long long r) {
  if (r == 0 || n == r) return 1;
  if (r > n) return 0;
  return (first[n] * INV[r] % mod * INV[n - r] % mod) % mod;
}
void sieve() {
  prime[0] = 1, prime[1] = 1;
  for (int i = 2; i * i < N; i++) {
    if (prime[i] == 0) {
      for (int j = i * i; j < N; j += i) prime[j] = 1;
    }
  }
}
void minprime() {
  minp[0] = 0, minp[1] = 1;
  for (int i = 2; i < N; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      for (int j = i * i; j < N; j += i) {
        if (minp[j] == 0) minp[j] = i;
      }
    }
  }
}
void JAI_SHREE_RAM() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a.begin(), a.end());
  map<long long, long long> m;
  for (int i = 0; i < n; i++) {
    m[a[i]]++;
  }
  if (abs(a[n - 1] - a[n - 2]) >= 2) {
    cout << 0 << "\n";
    return;
  }
  if (abs(a[n - 1] - a[n - 2]) == 0) {
    cout << first[n] << "\n";
    return;
  }
  long long invalid = first[n] * fermat(m[a[n - 2]] + 1) % mod;
  long long ans = (first[n] - invalid + mod) % mod;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fact();
  long long tttt = 1;
  cin >> tttt;
  while (tttt--) {
    JAI_SHREE_RAM();
  }
}
