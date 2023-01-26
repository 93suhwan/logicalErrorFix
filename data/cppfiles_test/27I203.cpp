#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream& operator<<(ostream& os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream& operator<<(ostream& os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  k--;
  if (m < n - 1 || m > (n * (n - 1)) / 2) {
    cout << "NO\n";
    return;
  }
  if (k > 2)
    cout << "YES\n";
  else if (k == 2) {
    if (m == (n * (n - 1)) / 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  auto start1 = high_resolution_clock::now();
  while (t--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop1 - start1);
}
