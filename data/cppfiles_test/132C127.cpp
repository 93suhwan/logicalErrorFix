#include <bits/stdc++.h>
using namespace std;
string tostr(long long int a) {
  stringstream rr;
  rr << a;
  return rr.str();
}
void _print(long long int t) { cerr << t; }
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
template <class T>
void print(vector<T> v) {
  for (T i : v) {
    cout << i << " ";
  }
  cout << endl;
}
const long long int mod = 1e9 + 7;
void solve() {
  long long int n, m, x, y, z, k, sum = 0, c1 = 0, c2 = 0, ans = 0;
  vector<long long int> a(7), b;
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  b = a;
  sort((b).begin(), (b).end());
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (i == j) continue;
      for (int k = 0; k < 7; k++) {
        if (i == j || j == k) continue;
        if ((a[i] + a[j] + a[k]) == b[6]) {
          cout << a[i] << " " << a[j] << " " << a[k] << endl;
          return;
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
