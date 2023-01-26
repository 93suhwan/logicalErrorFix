#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
template <class T>
void print(const T *const arr, long long int count) {
  for (long long int i = 0; i < count; ++i) {
    _print(arr[i]);
    cerr << " ";
  }
  cerr << '\n';
}
void Solve() {
  long long ll n, x;
  cin >> n;
  long long ll sq = sqrt(n);
  long long ll cb = cbrt(n);
  set<long long ll> second;
  for (long long ll i = 1; i <= sq; i++) {
    x = i * i;
    second.insert(x);
  }
  for (long long ll i = 1; i <= cb; i++) {
    x = (i * i * i);
    second.insert(x);
  }
  cout << second.size();
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
  for (long long int i = 1; i < T + 1; i++) {
    Solve();
    cout << '\n';
  }
  return 0;
}
