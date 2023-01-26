#include <bits/stdc++.h>
using namespace std;
const string yo = "YES";
const string no = "NO";
const int inf = 2000000000;
const long long infll = 9000000000000000000;
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long FIRSTTRUE(function<bool(long long)> f, long long lb, long long rb) {
  while (lb < rb) {
    long long mb = (lb + rb) / 2;
    f(mb) ? rb = mb : lb = mb + 1;
  }
  return lb;
}
long long LASTTRUE(function<bool(long long)> f, long long lb, long long rb) {
  while (lb < rb) {
    long long mb = (lb + rb + 1) / 2;
    f(mb) ? lb = mb : rb = mb - 1;
  }
  return lb;
}
template <class A>
void read(vector<A>& v);
template <class A, size_t second>
void read(array<A, second>& a);
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
template <class A, size_t second>
void read(array<A, second>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t second>
string to_string(bitset<second> b) {
  string res;
  for (int i = (0); (1) > 0 ? i < (second) : i > (second); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
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
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
template <class T>
void offset(long long o, T& x) {
  x += o;
}
template <class T>
void offset(long long o, vector<T>& x) {
  for (auto& a : x) offset(o, a);
}
template <class T, size_t second>
void offset(long long o, array<T, second>& x) {
  for (auto& a : x) offset(o, a);
}
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(mt_rng);
}
template <class T, class U>
void vti(vector<T>& v, U x, size_t n) {
  v = vector<T>(n, x);
}
template <class T, class U>
void vti(vector<T>& v, U x, size_t n, size_t m...) {
  v = vector<T>(n);
  for (auto& a : v) vti(a, x, m);
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int Max = 2e5 + 1;
const double pi = 3.141592653589793238462;
bool vis[Max] = {false};
long long dp[Max] = {0};
string s;
void solve() {
  long long n;
  read(n);
  vector<long long> v(n);
  read(v);
  if (n % 2 == 0) {
    print(yo);
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      print(yo);
      return;
    }
  }
  print(no);
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  read(t);
  for (int i = (0); (1) > 0 ? i < (t) : i > (t); i += (1)) {
    solve();
  }
}
