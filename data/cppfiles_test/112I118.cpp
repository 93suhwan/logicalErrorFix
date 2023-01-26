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
bool check(int a, int b, int c, int m) {
  if (m != 0) {
    return false;
  } else {
    int max = 0, sum = a + b + c;
    if (a > max) max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (sum - max >= max - 1)
      return true;
    else
      return false;
  }
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    while (m > 0 && (a - 2 >= 0 || b - 2 >= 0 || c - 2 >= 0)) {
      if (a >= b && a >= c && a - 2 >= 0) {
        a -= 2;
        m--;
      }
      if (b >= a && b >= c && b - 2 >= 0) {
        b -= 2;
        m--;
      }
      if (c >= b && c >= a && c - 2 >= 0) {
        c -= 2;
        m--;
      }
    }
    if (check(a, b, c, m))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
