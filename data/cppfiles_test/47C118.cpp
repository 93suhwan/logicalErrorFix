#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    n = n / 2;
    x = x * x % mod;
  }
  return res % mod;
}
long long modinv(long long n) { return power(n, mod - 2); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  long long x, y;
  cout << "and 1 2" << endl;
  cin >> x;
  cout << "or 1 2" << endl;
  cin >> y;
  long long s01 = x + y;
  cout << "and 1 3" << endl;
  cin >> x;
  cout << "or 1 3" << endl;
  cin >> y;
  long long s12 = x + y;
  cout << "and 2 3" << endl;
  cin >> x;
  cout << "or 2 3" << endl;
  cin >> y;
  long long s02 = x + y, i;
  v[1] = (s01 + s12 - s02) / 2;
  v[0] = s01 - v[1];
  v[2] = s12 - v[1];
  for (i = 4; i < n + 1; i++) {
    cout << "and " << i - 1 << " " << i << endl;
    cin >> x;
    cout << "or " << i - 1 << " " << i << endl;
    cin >> y;
    long long s = x + y;
    v[i - 1] = s - v[i - 2];
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  cout << endl;
  return 0;
}
