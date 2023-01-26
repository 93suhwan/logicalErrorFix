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
int n, m;
string s[1000004];
char ulta(char x) {
  int p = x;
  if (p >= 78)
    p = 65 + (78 - p);
  else
    p = 78 + (65 - p);
  return p;
}
void solution() {
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> s[i];
  for (j = 0; j < m; j++)
    if (j & 1)
      for (i = 0; i < n; i++) s[i][j] = ulta(s[i][j]);
  for (i = 0; i < n; i++) s[i] += i + 49;
  sort(s, s + n);
  for (i = 0; i < n; i++) _pa(s[i][m]);
  cout << '\n';
}
int32_t main() { solution(); }
