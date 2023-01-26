#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
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
void write(vector<long long> &v) {
  for (auto i : v) cout << i;
  cout << "\n";
}
void read(vector<long long> &v) {
  for (auto &i : v) cin >> i;
}
void solve() {
  long long n;
  cin >> n;
  char a[2][n];
  for (long long(i) = (0); (i) < (2); i++) {
    for (long long(j) = (0); (j) < (n); j++) {
      cin >> a[i][j];
    }
  }
  for (long long(j) = (0); (j) < (n - 1); j++) {
    if (a[0][j] == '0' || a[1][j] == '0' || a[0][j + 1] == '0' ||
        a[1][j + 1] == '0')
      continue;
    else {
      cout << "NO" << endl;
      return;
    }
  }
  if (a[1][n - 1] == '0')
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
