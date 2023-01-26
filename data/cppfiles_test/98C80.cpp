#include <bits/stdc++.h>
using namespace std;
template <class T>
void _p(T a) {
  cout << a << '\n';
}
template <class T>
void _pa(T a) {
  cout << a << ' ';
}
template <class T1, class T2>
void _p(T1 a, T2 b) {
  cout << a << ' ' << b << '\n';
}
template <class T1, class T2, class T3>
void _p(T1 a, T2 b, T3 c) {
  cout << a << ' ' << b << ' ' << c << '\n';
}
template <class T1, class T2, class T3, class T4>
void _p(T1 a, T2 b, T3 c, T4 d) {
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << '\n';
}
template <class T1, class T2, class T3, class T4, class T5>
void _p(T1 a, T2 b, T3 c, T4 d, T5 e) {
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << '\n';
}
template <class T>
void _pa(T a[], long long n) {
  long long i;
  for (i = 0; i < n; i++) cout << a[i] << ' ';
  cout << '\n';
}
template <class T>
void _p(vector<T> v) {
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(list<T> l) {
  for (auto x : l) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(multiset<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(unordered_set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T1, class T2>
void _p(map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void _p(unordered_map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void _p(map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    _p(x.second);
  }
  cout << '\n';
}
template <class T1, class T2>
void _p(unordered_map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    _p(x.second);
  }
  cout << '\n';
}
void solution() {
  string a, b;
  int i, n, c = 0;
  cin >> a >> b;
  map<char, int> mp;
  n = b.length();
  for (i = 0; i < 26; i++) mp[a[i]] = i;
  for (i = 1; i < n; i++) c += abs(mp[b[i]] - mp[b[i - 1]]);
  _p(c);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tcse;
  cin >> tcse;
  while (tcse--) solution();
}
