#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
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
int isPowerof2(int x) { return (x && !(x & x - 1)); }
void solve() {
  int l, r;
  cin >> l >> r;
  int s = l;
  int c = l;
  int d = 0;
  for (int i = l + 1; i <= r; i++) {
    s = (s & i);
    if (s == 0) {
      d++;
      s = c;
    } else {
      c = (c & i);
    }
  }
  int s1 = r;
  int c1 = r;
  int d1 = 0;
  for (int i = r - 1; i >= l; i--) {
    s1 = (s1 & i);
    if (s1 == 0) {
      d1++;
      s1 = c1;
    } else {
      c1 = (c1 & i);
    }
  }
  cout << min(d, d1) << nl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
