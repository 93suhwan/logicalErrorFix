#include <bits/stdc++.h>
using namespace std;
template <typename T>
T get_rand(T l, T r) {
  random_device rd;
  mt19937 gen(rd());
  return uniform_int_distribution<T>(l, r)(gen);
}
template <typename T>
T lcm(T a, T b) {
  return a * (b / __gcd(a, b));
}
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = 0; i < (int)v.size(); ++i) res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = 0; i < S; ++i) res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto x : v) {
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
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void freop(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int MOD = 1e9 + 7;
const int N = 3e6 + 5;
const long long INF = 9e18;
const int M = 3e3 + 5;
const double long pi = acos(-1);
const double long eps = 1e-12;
const int sq = 700;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void precalc() {}
void solve() {
  int n, k;
  read(n, k);
  vector<long long> a(n);
  read(a);
  sort(a.rbegin(), a.rend());
  long long ans = 0;
  vector<bool> used(n);
  for (int i = k * 2; i < n; ++i) ans += a[i];
  for (int i = k - 1; i >= 0; --i) {
    bool ok = 1;
    for (int j = k; j < 2 * k; ++j) {
      if (a[i] != a[j] && !used[j]) {
        used[j] = 1;
        ok = 0;
        break;
      }
    }
    ans += ok;
  }
  print(ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  read(t);
  precalc();
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
