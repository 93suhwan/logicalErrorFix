#include <bits/stdc++.h>
using namespace std;
void _print(int64_t t) { cerr << t; }
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
bool prime[100000];
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= 100000; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 100000; i += p) prime[i] = false;
    }
  }
}
long long binpow(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
int64_t invmd(int64_t n) { return (binpow(n, 1000000007 - 2)); }
void solve() {
  int64_t k;
  cin >> k;
  int64_t p2 = pow(2, k) - 2;
  int64_t p = ((binpow(4, p2) % 1000000007) * (6 % 1000000007)) % 1000000007;
  cout << p << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
