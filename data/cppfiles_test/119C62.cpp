#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
template <typename C>
void UNIQUE(vector<C> &v) {
  sort((v).begin(), (v).end());
  v.resize(unique((v).begin(), (v).end()) - v.begin());
}
template <typename T>
int sz(T &v) {
  return (int)(v.size());
}
template <class T>
void read(T &x) {
  cin >> x;
}
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double &d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A> &x) {
  for (auto &a : x) {
    read(a);
  }
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto &x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void solve() {
  int n, cnt = 0;
  read(n);
  vector<int> buildings(n);
  for (int i = 0; i < n; i++) {
    read(buildings[i]);
    cnt += buildings[i];
  }
  if (cnt % n)
    puts("1");
  else
    puts("0");
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
