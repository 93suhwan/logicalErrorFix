#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
template <typename T>
void print(T t) {
  cout << t << endl;
}
template <typename T, typename... Args>
void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
long long toint(const string& s) {
  stringstream ss;
  ss << s;
  long long x;
  ss >> x;
  return x;
}
string tostring(long long number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
void time() {}
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
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
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
  for (long long i = (0);
       (1) > 0 ? i < ((long long)(v).size()) : i > ((long long)(v).size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (long long i = (0); (1) > 0 ? i < (S) : i > (S); i += (1))
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
void DBG() {
  cerr << "]"
       << "\n";
}
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
template <class T, size_t S>
void offset(long long o, array<T, S>& x) {
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
const long long despacito = 1e9 + 7;
const long long despacito_huge = 1e18 + 7;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 5;
const long long N = 1e6 + 5;
long long n, m;
bool val(long long x, long long y) {
  if (x < 0 or y < 0 or x >= n or y >= m) {
    return false;
  }
  return true;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    long long k;
    read(n, m, k);
    string s[n];
    for (long long i = 0; i < n; i++) {
      read(s[i]);
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == '.') continue;
        long long c = 0;
        for (long long l = 1;; l++) {
          if (val(i - l, j - l) and val(i - l, j + l) and
              s[i - l][j - l] == '*' and s[i - l][j + l] == '*') {
            c++;
          } else {
            break;
          }
        }
        if (c >= k) {
          for (long long l = 0; l <= c; l++) {
            vis[i - l][j - l] = vis[i - l][j + l] = true;
          }
        }
      }
    }
    bool ans = true;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == '*' and !vis[i][j]) {
          ans = false;
        }
      }
    }
    if (!ans) {
      write("NO", "\n");
    } else {
      write("YES", "\n");
    }
  }
  return 0;
}
