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
template <class T>
void print(const T *const arr, long long int count) {
  for (long long int i = 0; i < count; ++i) {
    _print(arr[i]);
    cerr << " ";
  }
  cerr << '\n';
}
void Solve() {
  long long int n;
  cin >> n;
  long long int a[n], b[n];
  map<long long int, long long int> m1, m2;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    m1[a[i]]++;
    m2[b[i]]++;
  }
  long long int a1 = 0, a2 = 0;
  for (long long int i = 0; i < n; i++) {
    a1 += (m1[a[i]] - 1) * (m2[b[i]] - 1);
  }
  cout << ((n) * (n - 1) * (n - 2)) / 6 - a1;
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
