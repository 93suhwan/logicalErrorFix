#include <bits/stdc++.h>
using namespace std;
const int inf = 0;
const double eps = 0;
const int ms = 0;
const int md = 0;
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
void solve() {
  long long int n, k, ans = 0;
  cin >> n >> k;
  vector<long long int> a(n);
  for (__typeof(0) i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  for (long long int i = 0; i < n; i = i + k) {
    if (a[i] < 0) ans -= a[i];
  }
  for (long long int i = n - 1; i >= 0; i = i - k) {
    if (a[i] > 0) ans += a[i];
  }
  cout << 2 * ans - max(-a[0], a[n - 1]);
}
int main(void) {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
