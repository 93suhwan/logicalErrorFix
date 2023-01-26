#include <bits/stdc++.h>
using namespace std;
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
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void func() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b = a;
  reverse(b.begin(), b.end());
  for (int i = 0; i < n / 2; i++) {
    b[i] = (-1 * b[i]);
  }
  if (n % 2 == 1) {
    b[n / 2] = (b[n / 2] > 0 ? abs(a[0]) : -1 * abs(a[0]));
    b[0] = (b[0] > 0 ? b[0] + abs(a[n / 2]) : b[0] - abs(a[n / 2]));
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
}
int main() {
  init_code();
  double start1 = (double)clock();
  int t = 1;
  cin >> t;
  while (t--) func();
  double stop1 = (double)clock();
  double duration = (stop1 - start1) / CLOCKS_PER_SEC;
}
